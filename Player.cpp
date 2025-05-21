//
// Created by sadri on 20.05.2025.
//
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;


Player::Player(float width, float height, sf::Vector2f playerpos): height(height), width(width), playerpos(playerpos)
 {
    player.setSize({width, height});
    player.setFillColor(sf::Color::White);
    player.setPosition(playerpos);

}
void Player::playermovement1() {
    sf::Vector2f down{0,0.07};
    sf::Vector2f up{0,-0.07};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){


        if(player.getPosition().y <0) {

        }else {
            player.setFillColor(sf::Color(0, 0, 0));
            player.setPosition(player.getPosition()+up);
            player.setFillColor(sf::Color::White);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        if(player.getPosition().y > 400) {

        }else {
            player.setFillColor(sf::Color(0, 0, 0));
            player.setPosition(player.getPosition()+down);
            player.setFillColor(sf::Color::White);
        }
    }

}

void Player::playermovement2() {
    sf::Vector2f down{0,0.07};
    sf::Vector2f up{0,-0.07};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){


        if(player.getPosition().y <0) {

        }else {
            player.setFillColor(sf::Color(0, 0, 0));
            player.setPosition(player.getPosition()+up);
            player.setFillColor(sf::Color::White);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        if(player.getPosition().y > 400) {

        }else {
            player.setFillColor(sf::Color(0, 0, 0));
            player.setPosition(player.getPosition()+down);
            player.setFillColor(sf::Color::White);
        }
    }




}