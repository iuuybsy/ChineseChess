#ifndef SIDE_H
#define SIDE_H

#include "../common/stone_type_enum.h"
#include "../common/stone_side_enum.h"
#include "../pos/position.h"
#include "../stones/stones.h"

#include <vector>

class Side {
public:
    StoneSide side_;
    std::vector<Stone*> stones_{16};

    Side(StoneSide side);
    virtual ~Side();
};

#endif