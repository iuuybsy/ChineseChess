#include "../enums/stone_type_enum.h"
#include "../enums/stone_side_enum.h"
#include "../data_struct/position.h"

#include <unordered_set>

class StoneBase {
private:
    StoneType type_;
    StoneSide side_;
    Pos pos_;

public:
    std::unordered_set<Pos> valid_next_move_;

public:
    StoneBase(int x, int y, StoneSide side, StoneType type): pos_(Pos(x, y)), side_(side), type_(type) {}
    StoneBase(Pos pos, StoneSide side, StoneType type): pos_(pos), side_(side), type_(type) {}
    virtual ~StoneBase() {}

    virtual StoneType stone_type() const noexcept {
        return this->type_;
    }

    virtual StoneSide stone_side() const noexcept {
        return this->side_;
    }

    virtual int get_x() const noexcept {
        return this->pos_.x();
    }

    virtual int get_y() const noexcept {
        return this->pos_.y();
    }

    virtual void update_valid_move_set() = 0;
};