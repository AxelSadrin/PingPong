//
// Created by sadri on 24.05.2025.
//

#include "GameManager.h"

sf::Vector2f ballpos(800.f, 400.f);
sf::Vector2f p2pos(1570.f, 200.f);
sf::Vector2f p1pos(0.f, 200.f);
GameManager::GameManager() {

}

void GameManager::resetGame(Ball &ball, Player &player1, Player &player2) {
    ball.ball.setPosition(ballpos);
    player1.player.setPosition(p1pos);
    player2.player.setPosition(p2pos);

    clock1.reset();
    sf::sleep(sf::seconds(2.f));

}
