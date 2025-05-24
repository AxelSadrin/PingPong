//
// Created by sadri on 23.05.2025.
//

#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "GameManager.h"


class Score: public sf::Drawable {
    private:
    bool p1goal = false;
    bool p2goal = false;
    int player1Score = 0;
    int player2Score = 0;
    sf::Vector2f scorepos;
    sf::Text score;
    sf::Font font;




    public:

    Score(sf::Vector2f scorepos);
    void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(score, states);
    }
    void setScore(int& player1Score, int& player2Score);
    int getp1Score();
    int getp2Score();
    void goalScore(Ball& ball1,GameManager& game_manager,Player& player1,Player& player2);
};



#endif //SCORE_H
