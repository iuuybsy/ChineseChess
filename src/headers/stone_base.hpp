#include "../enums/stone_type_enum.hpp"

#include <unordered_set>

class StoneBase {
private:
    StoneType type;
    int x, y;

public:
    std::unordered_set<int> valid_next_move;

public:
    StoneBase(int _x, int _y, StoneType _type): x(_x), y(_y), type(_type) {}
    virtual ~StoneBase() {}

    virtual StoneType stone_type() {
        return this->type;
    }

    virtual int get_x() {
        return this->x;
    }

    virtual int get_y() {
        return this->y;
    }
};