#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Gameboard.hpp"
#include "Player.hpp"

bool victory_check(std::array<std::array<char,3>,3> & board, Player player){
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player.symbol && board[i][1] == player.symbol && board[i][2] == player.symbol) {
            return true;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player.symbol && board[1][i] == player.symbol && board[2][i] == player.symbol) {
            return true;
        }
    }
    if (board[0][0] == player.symbol && board[1][1] == player.symbol && board[2][2] == player.symbol) {
        return true;
    }
    if (board[0][2] == player.symbol && board[1][1] == player.symbol && board[2][0] == player.symbol) {
        return true;
    }
    return false;
}

bool equality_check(std::array<std::array<char,3>,3> & board){
    for ( std::size_t y{0}; y<3; y++){
        for ( std::size_t x{0}; x<3; x++){
            if (board[y][x]!='X' || board[y][x]!='O'){
                return false;
            }
    }
}
    return true;
}

void game_j1vsj2(std::array<std::array<char,3>,3> & board,Player player1,Player player2){
    int destination {};
    std::cout<<"Bienvenue dans le jeu du morpion"<<std::endl<<"Joueur 1 veuillez vous presenter et choisissez votre symbole"<<std::endl;
    player1 = create_player();
    std::cout<<"Joueur 2 veuillez a votre tour vous presenter, entrez votre nom: ";
    std::cin>>player2.name;
    player2.symbol = (player1.symbol == 'O') ? 'X' : 'O';
    std::cout<<"Debut de la partie !"<<std::endl;
    draw_game_board(board);
    while (victory_check(board,player1)==false && victory_check(board,player2)==false && equality_check(board)==false){
    display_board(board);
    std::cout<<std::endl;
    std::cout<<"C'est au tour de "<<player1.name<<std::endl;
    std::cout<<"Veuillez entrez un chiffre entre 0 et 8 : ";
     while (true) {
        std::cin >> destination;
        if (destination>=0 && destination<=8 && ( board[destination/3][destination%3]!= 'X' && board[destination/3][destination%3]!= 'O')) {
            break;
        } 
        else if (destination<0 || destination>8) {
            std::cout << "Votre chiffre est invalide, veuillez choisir un chiffre entre 0 et 8 : ";
        }
        else {
            std::cout << "Cet emplacement est deja joue, veuillez jouer dans un emplacement libre : ";
        }
     }
     board[destination/3][destination%3]=player1.symbol;
     if (victory_check(board,player1)==true){
        break;
     }
     else if (equality_check(board)==true) {
        break;
    }
     std::cout<<"C'est au tour de "<<player2.name<<std::endl;
     std::cout<<"Veuillez entrez un chiffre entre 0 et 8 : ";
     while (true) {
        std::cin >> destination;
        if (destination>=0 && destination<=8 && ( board[destination/3][destination%3]!= 'X' && board[destination/3][destination%3]!= 'O')) {
            break;
        } 
        else if (destination<0 || destination>8) {
            std::cout << "Votre chiffre est invalide, veuillez choisir un chiffre entre 0 et 8 : ";
        }
        else {
            std::cout << "Cet emplacement est deja joue, veuillez jouer dans un emplacement libre : ";
        }
     }
     board[destination/3][destination%3]=player2.symbol;

    }
    if ( victory_check(board,player1)==true ){
        std::cout<<player1.name<<" gagne la partie"<<std::endl;
    }
    else if ( victory_check(board,player2)){
        std::cout<<player2.name<<" gagne la partie"<<std::endl;
    }
    else if (equality_check(board)==true) {
        std::cout<<"Le jeu est fini il y a egalite"<<std::endl;
    }
}

void game_j1vsia(std::array<std::array<char,3>,3> & board,Player player1,Player player2){
    int destination {};
    std::cout<<"Bienvenue dans le jeu du morpion"<<std::endl<<"Joueur 1 veuillez vous presenter et choisissez votre symbole"<<std::endl;
    player1 = create_player();
    player2.name = "IA";
    player2.symbol = (player1.symbol == 'O') ? 'X' : 'O';
    std::cout<<"Debut de la partie !"<<std::endl;
    draw_game_board(board);
    while (victory_check(board,player1)==false && victory_check(board,player2)==false && equality_check(board)==false){
    display_board(board);
    std::cout<<std::endl;
    std::cout<<"C'est au tour de "<<player1.name<<std::endl;
    std::cout<<"Veuillez entrez un chiffre entre 0 et 8 : ";
    while (true) {
        std::cin >> destination;
        if (destination>=0 && destination<=8 && ( board[destination/3][destination%3]!= 'X' && board[destination/3][destination%3]!= 'O')) {
            break;
        } 
        else if (destination<0 || destination>8) {
            std::cout << "Votre chiffre est invalide, veuillez choisir un chiffre entre 0 et 8 : ";
        }
        else {
            std::cout << "Cet emplacement est deja joue, veuillez jouer dans un emplacement libre : ";
        }
     }
     board[destination/3][destination%3]=player1.symbol;
     if (victory_check(board,player1)==true){
        break;
     }
     else if (equality_check(board)==true){
        break;
     }
    std::cout<<"C'est au tour de l'IA"<<std::endl;
    destination = ia_move(board,player2.symbol,player1.symbol);
    board[destination/3][destination%3]=player2.symbol;
    }    
    if ( victory_check(board,player1)==true ){
        std::cout<<player1.name<<" gagne la partie"<<std::endl;
    }
    else if ( victory_check(board,player2)){
        std::cout<<"L'IA gagne la partie"<<std::endl;
    }
    else if (equality_check(board)==true) {
        std::cout<<"Le jeu est fini il y a egalite"<<std::endl;
    }
}

void game(std::array<std::array<char,3>,3> & board){
    std::cout<<"Bienvenue dans le jeu du TicTacToe!"<<std::endl;
    std::cout<<"Veuillez choisir votre mode de jeu: "<<std::endl;
    std::cout<<"1. J1 vs J2"<<std::endl;
    std::cout<<"2. J1 vs IA"<<std::endl;
    int mode;
    while (true) {
    std::cout<<"Mode de jeu : ";
    std::cin >> mode;
    draw_game_board(board);
    if (mode == 1 || mode == 2) {
        break;
    } 
    else {
        std::cout << "Mode de jeu invalide, veuillez choisir entre le mode 1 ou le mode 2 : "<<std::endl;
    }
    }
    if (mode == 1) {
        Player player1, player2;
        game_j1vsj2(board,player1,player2);
    } 
    else if (mode == 2) {
        Player player1, player2;
        game_j1vsia(board,player1,player2);
    }
}

