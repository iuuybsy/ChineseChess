#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "stone_type_enum.h"

namespace board {
    constexpr int WIDTH = 9;
    constexpr int HEIGHT = 10;
}

namespace logic {
    constexpr int QUAT_SEARCH_DIR[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    constexpr int DIAG_SEARCH_DIR[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
}

namespace init {
    constexpr int STONE_NUM[7] = {1, 2, 2, 2, 2, 2, 5};
    constexpr StoneType STONE_TYPE[7] = {StoneType::General, StoneType::Guard, 
        StoneType::Officer, StoneType::Cavalry, StoneType::Chariot, 
        StoneType::Artillery, StoneType::Infantry};
    constexpr int STONE_X[16] = {4, 3, 5, 2, 6, 1, 7, 0, 8, 1, 7, 0, 2, 4, 6, 8};
    constexpr int RED_STONE_Y[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 3, 3, 3, 3};
}

#endif
