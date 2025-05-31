#ifndef POSITION_H
#define POSITION_H

#include <functional>

class Pos {
private:
    int x_, y_;
public:
    explicit Pos(int x, int y) noexcept: x_(x), y_(y) {}

    const int x() const noexcept { return this->x_; }
    const int y() const noexcept { return this->y_; }

    void reset_pos(const Pos& pos_) noexcept { 
        this->x_ = pos_.x();
        this->y_ = pos_.y();
    }

    const bool operator==(const Pos& another) const noexcept { 
        return x_ == another.x_ && y_ == another.y_;
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
