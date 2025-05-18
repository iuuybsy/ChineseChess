#include "../enums/stone_type_enum.hpp"
#include "../enums/stone_side_enum.hpp"
#include "../data_struct/position.hpp"

#include <unordered_set>

class StoneBase {
private:
    StoneType type;
    StoneSide side;
    Pos pos;

public:
    std::unordered_set<Pos> valid_next_move;

public:
    StoneBase(int _x, int _y, StoneSide _side, StoneType _type): pos(Pos(_x, _y)), side(_side), type(_type) {}
    StoneBase(Pos _pos, StoneSide _side, StoneType _type): pos(_pos), side(_side), type(_type) {}
    virtual ~StoneBase() {}

    virtual StoneType stone_type() const noexcept {
        return this->type;
    }

    virtual StoneSide stone_side() const noexcept {
        return this->side;
    }

    virtual int get_x() const noexcept {
        return this->pos.x();
    }

    virtual int get_y() const noexcept {
        return this->pos.y();
    }

    virtual void update_valid_move_set() = 0;
};