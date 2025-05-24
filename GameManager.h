//
// Created by sadri on 24.05.2025.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Ball.h"


class GameManager {
private:

public:
    sf::Clock clock1;
    GameManager();
    void resetGame(Ball& ball,Player& player1,Player& player2);
};




#endif //GAMEMANAGER_H
