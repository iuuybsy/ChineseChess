#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace board {
    constexpr int WIDTH = 9;
    constexpr int HEIGHT = 10;
}

namespace logic {
    constexpr int QUAT_SEARCH_DIR[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    constexpr int DIAG_SEARCH_DIR[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
}

#endif
