#ifndef SIDE_H
#define SIDE_H

#include "../enums/stone_side_enum.h"
#include "../enums/stone_type_enum.h"
#include "../data_struct/position.h"
#include "stones.h"

#include <vector>

class Side {
public:
    StoneSide side_;
    std::vector<Stone*> stones_{16};

    Side(StoneSide side);
    virtual ~Side();
};

#endif