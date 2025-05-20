#include "../headers/stones.h"
#include "../headers/constants.h"

bool Stone::in_valid_pos(const int& x_cord, const int& y_cord) const noexcept {
    if (x_cord < 0 || x_cord >= board::WIDTH || y_cord < 0 || y_cord >= board::HEIGHT) {
        return false;
    }

    const StoneType cur_type = this->stone_type();
    const bool is_red = this->stone_side() == StoneSide::Red;

    if (cur_type == StoneType::General) {
        return (3 <= x_cord && x_cord <= 5) && (is_red ? y_cord < 3 : y_cord > 6);
    }
    else if (cur_type == StoneType::Guard) {
        if (3 > x_cord || 5 < x_cord) {
            return false;
        }
        bool is_in_palace = is_red ? y_cord <= 2 : y_cord >= 7;
        bool is_in_patrol_route = (x_cord + y_cord) % 2 == (is_red ? 1 : 0);
        return is_in_palace && is_in_patrol_route;
    }
    else if (cur_type == StoneType::Officer) {
        if (x_cord % 2 == 1) {
            return false;
        }
        return (y_cord % 4) == (is_red ? (x_cord % 4 == 0 ? 2 : 0) : (x_cord % 4 == 0 ? 3 : 1));
    }
    else if (cur_type == StoneType::Infantry) {
        bool is_retreating = is_red ? y_cord < 3 : y_cord > 6;
        if (is_retreating) {
            return false;
        }
        if ((is_red && y_cord < 5) || (!is_red && y_cord > 4)) {
            if (x_cord % 2 == 1) {
                return false;
            }
        }
    }

    return true;
}

void Stone::update_valid_move_set(const std::vector<std::vector<StoneSide>>& board_occupy) {
    this->valid_next_move_.clear();

    const int x_cord = this->get_x();
    const int y_cord = this->get_y();
    const StoneType cur_type = this->stone_type();
    const bool is_red = this->stone_side() == StoneSide::Red;

    if (cur_type == StoneType::General) {
        for (const auto& dir: logic::QUAT_SEARCH_DIR) {
            int x_next = x_cord + dir[0];
            int y_next = y_cord + dir[1];
            if (this->in_valid_pos(x_next, y_next)) {
                if (board_occupy[x_next][y_next] == (is_red ? StoneSide::Red : StoneSide::Green)) {
                    continue;
                }
                this->valid_next_move_.emplace(Pos(x_next, y_next));
            }
        }
    }
    else if (cur_type == StoneType::Guard) {
        for (const auto& dir: logic::DIAG_SEARCH_DIR) {
            int x_next = x_cord + dir[0];
            int y_next = y_next + dir[1];
            if (this->in_valid_pos(x_next, y_next)) {
                if (board_occupy[x_next][y_next] == (is_red ? StoneSide::Red : StoneSide::Green)) {
                    continue;
                }
                this->valid_next_move_.emplace(Pos(x_next, y_next));
            }
        }
    }
    else if (cur_type == StoneType::Officer) {
        for (const auto& dir: logic::DIAG_SEARCH_DIR) {
            int x_half_next = x_cord + dir[0];
            int y_half_next = y_cord + dir[1];
            int x_next = x_cord + 2 * dir[0];
            int y_next = y_cord + 2 * dir[1];
            if (this->in_valid_pos(x_next, y_next)) {
                if (board_occupy[x_half_next][y_half_next] != StoneSide::Blank) {
                    continue;
                }
                this->valid_next_move_.emplace(Pos(x_next, y_next));
            }
        }
    }
    else if (cur_type == StoneType::Cavalry) {
        for (const auto& orth_dir: logic::QUAT_SEARCH_DIR) {
            int x_orth_next = x_cord + orth_dir[0];
            int y_orth_next = y_cord + orth_dir[1];
            if (!this->in_valid_pos(x_orth_next, y_orth_next)) {
                continue;
            }
            else if (board_occupy[x_orth_next][y_orth_next] != StoneSide::Blank) {
                continue;
            }
            for (const auto& diag_dir: logic::DIAG_SEARCH_DIR) {
                int x_next = x_orth_next + diag_dir[0];
                int y_next = y_orth_next + diag_dir[1];
                if (x_next == x_cord || y_next == y_cord || !this->in_valid_pos(x_next, y_next)) {
                    continue;
                }
                this->valid_next_move_.emplace(Pos(x_next, y_next));
            }
        }
    }
    else if (cur_type == StoneType::Chariot) {
        for (const auto& dir: logic::QUAT_SEARCH_DIR) {
            int x_next = x_cord + dir[0];
            int y_next = y_cord + dir[1];
            while (this->in_valid_pos(x_next, y_next)) {
                if (board_occupy[x_next][y_next] == (is_red ? StoneSide::Red : StoneSide::Green)) {
                    break;
                }
                this->valid_next_move_.emplace(Pos(x_next, y_next));
                x_next += dir[0];
                y_next += dir[1];
            }
        }
    }
    else if (cur_type == StoneType::Artillery) {
        for (const auto& dir: logic::QUAT_SEARCH_DIR) {
            int x_next = x_cord + dir[0];
            int y_next = y_cord + dir[1];
            while (this->in_valid_pos(x_next, y_next)) {
                if (board_occupy[x_next][y_next] != StoneSide::Blank) {
                    x_next += dir[0];
                    y_next += dir[1];
                    while (this->in_valid_pos(x_next, y_next)) {
                        if (board_occupy[x_next][y_next] == (is_red ? StoneSide::Red : StoneSide::Green)) {
                            break;
                        }
                        else if (board_occupy[x_next][y_next] == StoneSide::Blank) {
                            continue;
                        }
                        else {
                            this->valid_next_move_.emplace(Pos(x_next, y_next));
                        }
                    }
                    break;
                }
                this->valid_next_move_.emplace(Pos(x_next, y_next));
                x_next += dir[0];
                y_next += dir[1];
            }
        }
    }
    else if (cur_type == StoneType::Infantry) {
        if (is_red) {
            if (y_cord < 5) {
                this->valid_next_move_.emplace(Pos(x_cord, y_cord + 1));
            }
            else {
                for (const auto& dir: logic::QUAT_SEARCH_DIR) {
                    int x_next = x_cord + dir[0];
                    int y_next = y_cord + dir[1];
                    if (!this->in_valid_pos(x_next, y_next) || y_next < y_cord) {
                        continue;
                    }
                    this->valid_next_move_.emplace(Pos(x_next, y_next));
                }
            }
        }
        else {
            if (y_cord > 4) {
                this->valid_next_move_.emplace(Pos(x_cord, y_cord - 1));
            }
            else {
                for (const auto& dir: logic::QUAT_SEARCH_DIR) {
                    int x_next = x_cord + dir[0];
                    int y_next = y_cord + dir[1];
                    if (!this->in_valid_pos(x_next, y_next) || y_next > y_cord) {
                        continue;
                    }
                    this->valid_next_move_.emplace(Pos(x_next, y_next));
                }
            }
        }
    }
}
