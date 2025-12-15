#include <iostream>
#include "Gameboard.hpp"

void draw_game_board_help(std::array<std::array<char,3>,3> & board){
    for ( std::size_t y {0}; y<3; y++){
        for (std::size_t x {0}; x<3; x++){
            board[y][x]='0' + (x+3*y);
        }
    }
}

void draw_game_board(std::array<std::array<char,3>,3> & board){
    for ( std::size_t y {0}; y<3; y++){
        for (std::size_t x {0}; x<3; x++){
            board[y][x]='.';
        }
    }
}

void display_board(std::array<std::array<char,3>,3> & board){
        for ( std::size_t y{0}; y<3; y++){
        for ( std::size_t x{0}; x<3; x++){
            std::cout<<board[y][x];
        };
        std::cout<<std::endl;
    };
}
