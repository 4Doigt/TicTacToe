#include "Ia.hpp"

int ia_move(std::array<std::array<char,3>,3> & board, char ia_symbol, char player_symbol){

    if (board[1][1] != player_symbol && board[1][1] != ia_symbol)
        return 4;

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player_symbol && board[i][1] == player_symbol && board[i][2] != ia_symbol)
            return i * 3 + 2;
        if (board[i][0] == player_symbol && board[i][2] == player_symbol && board[i][1] != ia_symbol)
            return i * 3 + 1;
        if (board[i][1] == player_symbol && board[i][2] == player_symbol && board[i][0] != ia_symbol)
            return i * 3 + 0;
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player_symbol && board[1][j] == player_symbol && board[2][j] != ia_symbol)
            return 2 * 3 + j;
        if (board[0][j] == player_symbol && board[2][j] == player_symbol && board[1][j] != ia_symbol)
            return 1 * 3 + j;
        if (board[1][j] == player_symbol && board[2][j] == player_symbol && board[0][j] != ia_symbol)
            return 0 * 3 + j;
    }

    if (board[0][0] == player_symbol && board[1][1] == player_symbol && board[2][2] != ia_symbol)
        return 8;
    if (board[0][0] == player_symbol && board[2][2] == player_symbol && board[1][1] != ia_symbol)
        return 4;
    if (board[1][1] == player_symbol && board[2][2] == player_symbol && board[0][0] != ia_symbol)
        return 0;
    if (board[0][2] == player_symbol && board[1][1] == player_symbol && board[2][0] != ia_symbol)
        return 6;
    if (board[0][2] == player_symbol && board[2][0] == player_symbol && board[1][1] != ia_symbol)
        return 4;
    if (board[1][1] == player_symbol && board[2][0] == player_symbol && board[0][2] != ia_symbol)
        return 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != player_symbol && board[i][j] != ia_symbol)
                return i * 3 + j;
        }
    }
}
