#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"

#include <iostream>

#include "Player.h"
#pragma once



extern const unsigned int WINDOW_WIDTH = 1600;
extern const unsigned int WINDOW_HEIGHT = 800;



Ball::Ball(double radius, sf::Vector2f position) {


    ball.setRadius(radius);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(position);
}
void Ball::setSpeed(float v){
    speed = v;

}
int Ball::getSpeed() {
    return speed;

}
void Ball::setcollission1() {
    collisionhit1 = true;
}
void Ball::setcollission2() {
    collisionhit2 = true;
}

void Ball::collisiondetection(Player& player,Player& player2) {
    sf::FloatRect boundingplayer1box = player.player.getGlobalBounds();
    sf::FloatRect boundingplayer2box = player2.player.getGlobalBounds();
    sf::FloatRect boundingballBox = ball.getGlobalBounds();


    if (boundingballBox.findIntersection(boundingplayer1box)  && cooldownClock.getElapsedTime().asSeconds() > 0.1f){
        setcollission1();
        cooldownClock.restart();

    }
    if (boundingballBox.findIntersection(boundingplayer2box)&& cooldownClock.getElapsedTime().asSeconds() > 0.1f) {
        setcollission2();
        cooldownClock.restart();
    }

}
void Ball::move(sf::Vector2f& direction,float speed,float player1speedangle,float player2speedangle) {

    direction = direction*speed;
    ball.setFillColor(sf::Color(0, 0, 0));
    ball.setPosition(ball.getPosition()+direction);
    ball.setFillColor(sf::Color(255, 255, 255));
   if(ball.getPosition().y > WINDOW_HEIGHT-10) {
       direction.y = direction.y* -1;
       ball.setFillColor(sf::Color(255, 255, 255));
   }
    if(ball.getPosition().y < 0) {
        direction.y = direction.y* -1;
        ball.setPosition(ball.getPosition()+direction);
    }

    if(collisionhit1) {

        direction.x = direction.x*-1;
        direction.y = direction.y* -1;
        direction.x = direction.x * player1speedangle;
        ball.setPosition(ball.getPosition()+direction);
        collisionhit1 = false;

    }
    if(collisionhit2) {
        direction.x = direction.x*-1;
        direction.y = direction.y* -1;
        direction.x = direction.x * player2speedangle;
        ball.setPosition(ball.getPosition()+direction);
        collisionhit2 = false;

    }

    direction = direction/speed;
}
