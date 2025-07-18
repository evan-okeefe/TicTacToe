cmake_minimum_required(VERSION 3.31)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe main.cpp)

set_target_properties(TicTacToe PROPERTIES LINK_FLAGS "-static -static-libgcc -static-libstdc++")
