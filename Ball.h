//
// Created by sadri on 20.05.2025.
//
#include <SFML/Graphics.hpp>
#include <vector>
#ifndef BALL_H
#define BALL_H
using namespace std;


class Ball: public sf::Drawable {
  private:
    float speed;
    double radius;
    sf::Vector2f position;
  sf::FloatRect boundingBox = ball.getGlobalBounds();
    sf::CircleShape ball;


  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
    target.draw(ball, states);
  }


  public:

    Ball(double radius, sf::Vector2f position);
    void setSpeed(float v);
    int getSpeed();
    void Move(sf::Vector2f& position,float speed);

};



#endif //BALL_H
