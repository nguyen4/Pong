#include <SFML/Graphics.hpp>

#include <iostream>
#include "globalVar.h"
#include "Paddle.hpp"
#include <math.h>
#include "Ball.hpp"
#include "UIElement.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Pong");
    UIElement UI;
    Paddle Left(true);
    Paddle Right(false);
    Ball ball;
    sf::Clock clock;
    window.setFramerateLimit(60);
    //sf::Time time;
    
    //set up game UI
    
    while (window.isOpen())
    {
        sf::Event Event;
        
        //Handle all Events
        while (window.pollEvent(Event))
        {
            switch (Event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("New window width: %i New window height: %i\n", Event.size.width, Event.size.height);
                    break;
            }
        }
        
        // Update the game
        window.clear();
        
        // draw objects here
        Left.drawto(window);
        Right.drawto(window);
        
        //printf("Time Elapsed = %f", timeElapsed);
        if (ball.touchedPaddle(&Left) == 1){
            ball.changeDirection(1, &Left);
            
        } else if (ball.touchedPaddle(&Right) == 2){
            ball.changeDirection(2, &Right);
            
        } else if (ball.touchedWall()){
            ball.changeDirection(3);
        }
        
        if (ball.isGameOver()){
            if (ball.leftWon()){
                Left.addOne();
            }
            
            if (ball.rightWon()){
                Right.addOne();
            }
            
            clock.restart();
            ball.reset();
            
        } else if (clock.getElapsedTime().asSeconds() >= 2) {
            ball.drawto(window);
        }
        
        // draw scores
        UI.drawto(window);
        window.display();
    }
}
