#include "headers/side.h"
#include "headers/constants.h"
#include "data_struct/position.h"

#include <iostream>

Side::Side(StoneSide side): side_(side) {
    int ind = 0;
    for (size_t i = 0; i < sizeof(init::STONE_NUM) / sizeof(init::STONE_NUM[0]); ++i) {
        int ind = 0;
        for (const auto& num: init::STONE_NUM) {
            for (int i = 0; i != num; ++i) {
                int x_pos = init::STONE_X[ind];
                int y_pos = side_ == StoneSide::Red ? init::RED_STONE_Y[ind] : 9 - init::RED_STONE_Y[ind];
                stones_[ind] = new Stone(Pos(x_pos, y_pos), side_, init::STONE_TYPE[i]);
            }
        }
    }
}

Side::~Side() {
    for (auto& stone_ptr: stones_) {
        delete stone_ptr;
        stone_ptr = nullptr;
    }
}

