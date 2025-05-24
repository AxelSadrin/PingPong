#include "Score.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


extern const unsigned int WINDOW_WIDTH;


Score::Score(sf::Vector2f scorepos): scorepos(scorepos),font("../Assets/fonts/Rubik-Regular.ttf"), score(font){






    score.setFont(font);
    score.setPosition(scorepos);
    score.setFillColor(sf::Color::White);
    score.setCharacterSize(100);

    score.setString(std::to_string(player1Score)+ ":" +std::to_string(player2Score));



}


void Score:: setScore(int& player1Score, int& player2Score) {

    if(p1goal) {
        player1Score += 1;
        p1goal = false;
    }
    if(p2goal) {
        player2Score += 1;
        p2goal = false;
    }
    score.setString(std::to_string(player1Score)+ ":" +std::to_string(player2Score));

}
int Score::getp1Score() {

    return player1Score;
}

int Score::getp2Score() {

    return player2Score;
}
void Score::goalScore(Ball& ball1,GameManager& game_manager,Player& player1,Player& player2) {
    if(ball1.ball.getPosition().x > WINDOW_WIDTH - ball1.ball.getRadius() ) {
        p1goal = true;
      setScore(player1Score, player2Score);
        game_manager.resetGame(ball1,player1,player2);
    }
    if(ball1.ball.getPosition().x < 0 +ball1.ball.getRadius() ) {
        p2goal = true;
        setScore(player1Score, player2Score);
        game_manager.resetGame(ball1,player1,player2);
    }
}


