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
        int movspeed;




    public:
    sf::RectangleShape player;
    Player(float width, float height,sf::Vector2f playerpos);

    void playermovement1();
    void playermovement2();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(player, states);
    }

};



#endif //PLAYER_H
