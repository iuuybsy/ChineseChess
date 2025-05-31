#include "game.h"
#include "stone_side_enum.h"
#include "constants.h"

#include <vector>

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
    if (!this->board_[start_point]->is_alive()) {
        return;
    }
    if (!this->board_[start_point]->valid_next_move_.count(end_point)) {
        return;
    }
    this->board_[start_point]->pos_.reset_pos(end_point);
    if (this->board_.count(end_point)) {
        this->board_[end_point]->dead();
    }

    std::vector<std::vector<StoneSide>> board_occupy(board::WIDTH, std::vector<StoneSide>(board::HEIGHT, StoneSide::Blank));
    for (auto iter = this->board_.begin(); iter != this->board_.end(); ++iter) {
        if (!iter->second->is_alive()) {
            continue;
        }
        board_occupy[iter->second->pos_.x()][iter->second->pos_.y()] = iter->second->stone_side();
    }

    for (auto iter = this->board_.begin(); iter != this->board_.end(); ++iter) {
        if (!iter->second->is_alive()) {
            continue;
        }
        iter->second->update_valid_move_set(board_occupy);
    }
}
