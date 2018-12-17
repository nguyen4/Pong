#include <SFML/Graphics.hpp>

#include <iostream>
#include "globalVar.h"
#include "Paddle.hpp"
#include <math.h>
#include "Ball.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Pong");
    Paddle Left(true);
    Paddle Right(false);
    Ball ball;
    
    //set up game UI
    ball.drawto(window);
    
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
        
        ball.drawto(window);
        
        if (ball.touchedPaddle(&Left) == 1){
            ball.changeDirection(1, &Left);
        }
        else if (ball.touchedPaddle(&Right) == 2){
            ball.changeDirection(2, &Right);
        }
        else if (ball.touchedWall()){
            ball.changeDirection(3);
        }
        
        window.display();
    }
}
