#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Player.h"
#include <optional>

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
void Ball::Move(sf::Vector2f& direction,float speed) {
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
    direction = direction/speed;



}
