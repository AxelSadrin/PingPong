//
// Created by sadri on 20.05.2025.
//
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <random>

#include <iostream>
using namespace std;
float random_float(float min, float max);


Player::Player(float width, float height, sf::Vector2f playerpos,float angle,float speed): height(height), width(width), playerpos(playerpos),angle(angle),speed(speed)
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
            player.setPosition(player.getPosition()+up*speed);
            player.setFillColor(sf::Color::White);
            angle = random_float(0.1f,2.0f);
            setangle(angle);
        }

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

        if(player.getPosition().y > 500) {

        }else {
            player.setFillColor(sf::Color(0, 0, 0));
            player.setPosition(player.getPosition()+down*speed);
            player.setFillColor(sf::Color::White);
            angle = random_float(0.1f,2.0f);
            setangle(angle);
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
            player.setPosition(player.getPosition()+up*speed);
            player.setFillColor(sf::Color::White);
            angle = random_float(0.1f,2.0f);
            setangle(angle);
        }



    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {


        if(player.getPosition().y > 500) {

        }else {
            player.setFillColor(sf::Color(0, 0, 0));
            player.setPosition(player.getPosition()+down*speed);
            player.setFillColor(sf::Color::White);
            angle = random_float(0.1f,2.0f);
            setangle(angle);

        }


    }

}
float Player::getangle(){


    return angle;
}
void Player::setangle(float angle){


    this->angle = angle;
}
float Player::getspeed() {
    return speed;
}
void Player::setspeed(float speed) {
    this->speed = speed;
}


float random_float(float min, float max) {

    return ((float)rand() / RAND_MAX) * (max - min) + min;

}