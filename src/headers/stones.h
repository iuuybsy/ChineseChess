#ifndef STONES_H
#define STONES_H

#include "../enums/stone_side_enum.h"
#include "../enums/stone_type_enum.h"
#include "../data_struct/position.h"
#include "stone_base.h"


class Stone: public StoneBase {
private:
    bool in_valid_pos(const int& x_cord, const int& y_cord) const noexcept;
public:
    Stone(int x, int y, StoneSide side, StoneType type): StoneBase(x, y, side, type) {}
    Stone(Pos pos, StoneSide side, StoneType type): StoneBase(pos, side, type) {}
    virtual ~Stone() override = default;

    virtual void update_valid_move_set(const std::vector<std::vector<StoneSide>>& board_occupy) override;
};

#endif
