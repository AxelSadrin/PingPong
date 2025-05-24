#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Ball.h"
#include "Player.h"
#include "Score.h"

using namespace std;

const unsigned int WINDOW_WIDTH = 1600;
const unsigned int WINDOW_HEIGHT = 800;
sf::Vector2f ballposition(800.f, 400.f);
sf::Vector2f player2pos(1570.f, 200.f);
sf::Vector2f player1pos(0.f, 200.f);
sf::Vector2f dir(0.01f,0.01f);
sf::Vector2f scorepos(750,50);



float player1angle;
float player2angle;


int main()
{
    Score score = Score(scorepos);
    Ball ball1 =  Ball(10.0f,ballposition);
    Player player2 = Player(30,300,player2pos,1,2);
    Player player1 = Player(30,300,player1pos,1,2);
    GameManager manager = GameManager();
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "PingPong");




    // Start the game loop
    while (window.isOpen())
    {

        sf::Time elapsed = manager.clock1.getElapsedTime(); // Zeit seit Start
        float timeInSeconds = elapsed.asSeconds();
        player1angle= player1.getangle();


        player2angle = player2.getangle();
        ball1.collisiondetection(player1,player2);
        ball1.move(dir,4*(1+timeInSeconds/10),player1angle,player2angle);
        score.goalScore(ball1,manager,player1,player2);
        player1.playermovement1();
        player2.playermovement2();
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        window.clear();
        window.draw(score);
        window.draw(player1);
        window.draw(player2);
        window.draw(ball1);


       
        
        // Update the window
        window.display();
    }
}

