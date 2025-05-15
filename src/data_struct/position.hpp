#ifndef POSITION_H
#define POSITION_H

#include <functional>

class Pos {
private:
    int _x, _y;
public:
    explicit Pos(int _x, int _y) noexcept: _x(_x), _y(_y) {}

    const int x() const noexcept { return this->_x; }
    const int y() const noexcept { return this->_y; }

    const bool operator==(const Pos& another) const noexcept { 
        return _x == another._x && _y == another._y;
    }


};

namespace std {
    template <>
    struct hash<Pos> {
        size_t operator()(const Pos& p) const noexcept {
            std::hash<int> int_hasher;
            return int_hasher(p.x()) ^ (int_hasher(p.y()) << 1);
        }
    };
}

#endif
