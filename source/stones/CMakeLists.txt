cmake_minimum_required(VERSION 3.20)
add_library(ChessStoneLib stones.cpp)
target_include_directories(ChessStoneLib PUBLIC ${PROJECT_SOURCE_DIR}/include/stones)
target_include_directories(ChessStoneLib PUBLIC ${PROJECT_SOURCE_DIR}/include/common)
target_include_directories(ChessStoneLib PUBLIC ${PROJECT_SOURCE_DIR}/include/pos)