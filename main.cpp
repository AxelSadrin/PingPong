#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Ball.h"
#include "Player.h"
using namespace std;

const unsigned int WINDOW_WIDTH = 1600;
const unsigned int WINDOW_HEIGHT = 800;
sf::Vector2f ballposition(800.f, 400.f);
sf::Vector2f player1pos(1570.f, 200.f);
sf::Vector2f player2pos(0.f, 200.f);
sf::Vector2f dir(0.01f,0.01f);
sf::Clock clock1;



int main()
{
    Ball ball1 =  Ball(10.0f,ballposition);
    Player player1 = Player(30,400,player1pos);
    Player player2 = Player(30.0f,400.0f,player2pos);
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "PingPong");




    // Start the game loop
    while (window.isOpen())
    {
        //Arena field begin
        sf::CircleShape middle;
        sf::CircleShape middlecircle;
        sf::RectangleShape middleline1;
        sf::RectangleShape middleline2;
        middle.setFillColor(sf::Color::White);
        middlecircle.setFillColor(sf::Color::Black);
        middlecircle.setOutlineThickness(10.f);
        middlecircle.setOutlineColor(sf::Color(sf::Color::White));
        middleline1.setFillColor(sf::Color::White);
        middleline2.setFillColor(sf::Color::White);
        middle.setRadius(10.f);
        middlecircle.setRadius(100.f);
        middle.setPosition(sf::Vector2f{800.f,400.f});
        middlecircle.setPosition(sf::Vector2f{710.f,305.f});
        middleline1.setSize(sf::Vector2f(20,250));
        middleline2.setSize(sf::Vector2f(20,250));
        middleline1.setPosition(sf::Vector2f{800.f,0.f});
        middleline2.setPosition(sf::Vector2f{800.f,550.f});
        //Arena field end

        sf::Time elapsed = clock1.getElapsedTime(); // Zeit seit Start
        float timeInSeconds = elapsed.asSeconds();
        ball1.collisiondetection(player1,player2);
        ball1.move(dir,4*(1+timeInSeconds/1000000));

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
        window.draw(middleline1);
        window.draw(middleline2);

        window.draw(middlecircle);
        window.draw(middle);
        window.draw(player1);
        window.draw(player2);
        window.draw(ball1);


       
        
        // Update the window
        window.display();
    }
}

