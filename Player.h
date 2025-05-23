//
// Created by sadri on 20.05.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/Glsl.hpp>


class Player : public sf::Drawable{
    private:

        float height;
        float width;
        sf::Vector2f playerpos;
        float angle = 1;
        float speed = 3;




    public:
    sf::RectangleShape player;
    Player(float width, float height,sf::Vector2f playerpos,float angle,float speed);

    void playermovement1();
    void playermovement2();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(player, states);
    }
    float getangle();
    void setangle(float angle);
    float getspeed();
    void setspeed(float speed);
};



#endif //PLAYER_H
