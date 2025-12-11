#include <iostream>
#include "Player.hpp"


Player create_player(){
    Player player {"",'\0'};
    std::cout << "Veuillez entrer le nom du joueur : ";
    std::cin >> player.name;
    std::cout << "Veuillez choisir entre X et O comme symbole : ";
    while (true) {
        std::cin >> player.symbol;
        if (player.symbol == 'X' || player.symbol == 'O') {
            break;
        } 
        else {
            std::cout << "Votre symbole est invalide, veuillez choisir entre X et O : ";
        }
    }
    return player;
}
