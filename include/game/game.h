#ifndef GAME_H
#define GAME_H

#include "../stones/stones.h"
#include "../side/side.h"
#include "../pos/position.h"

#include <unordered_map>

class Game {
private:
    Side* red_side_;
    Side* green_side_;
    bool is_red_turn;
    bool is_game_finish;

    std::unordered_map<Pos, Stone*> board_;

public:
    Game();
    ~Game();

    void move(Pos start_point, Pos end_point);
};

#endif
