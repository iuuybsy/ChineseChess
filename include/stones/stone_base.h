#ifndef STONE_BASE_H
#define STONE_BASE_H

#include "stone_type_enum.h"
#include "stone_side_enum.h"
#include "../pos/position.h"

#include <unordered_set>
#include <vector>

class StoneBase {
private:
    bool is_alive_;
    StoneType type_;
    StoneSide side_;

public:
    Pos pos_;
    std::unordered_set<Pos> valid_next_move_;

public:
    StoneBase(int x, int y, StoneSide side, StoneType type): pos_(Pos(x, y)), side_(side), type_(type), is_alive_(true) {}
    StoneBase(Pos pos, StoneSide side, StoneType type): pos_(pos), side_(side), type_(type), is_alive_(true) {}
    virtual ~StoneBase() {}

    virtual StoneType stone_type() const noexcept {
        return this->type_;
    }

    virtual StoneSide stone_side() const noexcept {
        return this->side_;
    }

    virtual const int get_x() const noexcept {
        return this->pos_.x();
    }

    virtual const int get_y() const noexcept {
        return this->pos_.y();
    }

    virtual const bool is_alive() const noexcept {
        return this->is_alive_;
    }

    virtual void dead() noexcept {
        this->is_alive_ = false;
    }

    virtual void update_valid_move_set(const std::vector<std::vector<StoneSide>>& board_occupy) = 0;
};

#endif
