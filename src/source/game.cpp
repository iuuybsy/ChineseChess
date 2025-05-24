#include "headers/game.h"
#include "enums/stone_side_enum.h"

Game::Game(): is_red_turn(true), is_game_finish(false) {
    red_side_ = new Side(StoneSide::Red);
    green_side_ = new Side(StoneSide::Green);

    for (const auto& ptr: red_side_->stones_) {
        board_[ptr->pos_] = ptr;
    }

    for (const auto& ptr: green_side_->stones_) {
        board_[ptr->pos_] = ptr;
    }
}

Game::~Game() {
    delete red_side_;
    red_side_ = nullptr;

    delete green_side_;
    green_side_ = nullptr;
}

void Game::move(Pos start_point, Pos end_point) {
    if (!this->board_.count(start_point)) {
        return;
    }
    if (!this->board_[start_point]->valid_next_move_.count(end_point)) {
        
    }
}
