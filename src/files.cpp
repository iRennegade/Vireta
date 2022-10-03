
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/background.hpp"
#include "../include/cursor.hpp"
#include "../include/icon.hpp"
#include "../include/baby.hpp"

using namespace std;

namespace vireta_files {
  void write_all() {
    string temp = string(getenv("TEMP"));
    ofstream png(temp + string("\\background.png"), ios::out | ios::binary);
    png.write(reinterpret_cast<char*>(background_bytes), sizeof(background_bytes));
    png.close();

    ofstream cur(temp + string("\\eye.cur"), ios::out | ios::binary);
    cur.write(reinterpret_cast<char*>(cursor_bytes), sizeof(cursor_bytes));
    cur.close();

    ofstream ico(temp + string("\\icon.ico"), ios::out | ios::binary);
    ico.write(reinterpret_cast<char*>(icon_bytes), sizeof(icon_bytes));
    ico.close();

    ofstream wav(temp + string("\\baby.wav"), ios::out | ios::binary);
    wav.write(reinterpret_cast<char*>(baby_bytes), sizeof(baby_bytes));
    wav.close();
  }
}
