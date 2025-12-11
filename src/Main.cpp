#include "Game.hpp"
#include "Gameboard.hpp"
#include "Player.hpp"
#include <iostream>

int main(){
    std::array<std::array<char,3>,3> board;
    draw_game_board(board);
    game(board);
    return 0;
}