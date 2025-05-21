//
// Created by sadri on 20.05.2025.
//
#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#ifndef BALL_H
#define BALL_H
using namespace std;


class Ball: public sf::Drawable {
  private:
    bool collisionhit1 = false;
  bool collisionhit2 = false;
    float speed;
    double radius;
    sf::Vector2f position;

    sf::CircleShape ball;


  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
    target.draw(ball, states);
  }


  public:

    Ball(double radius, sf::Vector2f position);
    void setSpeed(float v);
    int getSpeed();
    void setcollission1();
    void setcollission2();
    void move(sf::Vector2f& position,float speed);
    void collisiondetection(Player& player,Player& player2);

};



#endif //BALL_H
