#pragma once
#include <raylib.h>
#include <iostream>

using namespace std;

inline const Color green = {173, 204, 96, 255};
inline const Color darkGreen = {43, 51, 24, 255};
inline const int SCREEN_WIDTH = 750;
inline const int SCREEN_HEIGHT = 750;
inline const char* SCREEN_TITLE = "Snake Game";
inline const int FRAME_PER_SEC = 60;
inline const int CELL_SIZE = 30;
inline const int CELL_COUNT = (SCREEN_WIDTH / CELL_SIZE);
inline const int OFFSET = 75;