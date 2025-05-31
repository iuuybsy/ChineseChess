cmake_minimum_required(VERSION 3.20)
project(ChineseChessLogic CXX)

add_subdirectory(source/game)
add_subdirectory(source/side)
add_subdirectory(source/stones)

add_executable(ChineseChessLogic main.cpp)

target_link_libraries(ChineseChessLogic PUBLIC ChessStoneLib ChessSideLib ChessGameLib)
