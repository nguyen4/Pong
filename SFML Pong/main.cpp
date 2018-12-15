#include <SFML/Graphics.hpp>

#include <iostream>
#include "globalVar.h"
#include "Paddle.hpp"
#include <math.h>

class Ball{
public:
    Ball();
    void drawto(sf::RenderWindow &window);
    void shoots();
    void changeDirection(int event);
    float leftSide();
    float rightSide();
    float topBound();
    float bottomBound();
    bool isLeft();
    int touchedPaddle(Paddle* paddle);
    
private:
    sf::RectangleShape ball;
    float       length;
    float       width;
    float       velocity;
};

Ball::Ball(){
    length = 35;
    width = 35;
    velocity = 7;
    ball.setSize({width, length});
    ball.setOrigin(width/2.0f, length/2.0f);
    ball.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    ball.setFillColor(sf::Color::Green);

}

void Ball::drawto(sf::RenderWindow &window){
    window.draw(ball);
}

void Ball::shoots(){
    ball.move(velocity, 0);
}

void Ball::changeDirection(int event){ //might change the logic of change direction;
    if (event == 1){
        velocity = fabs(velocity);
    }
    if (event == 2){
        velocity = (-1) * velocity;
    }
}

//returns left global bound x of ball
float Ball::leftSide(){
    return ball.getPosition().x - (width/2);
}

//returns right global bound x of ball
float Ball::rightSide(){
    return ball.getPosition().x + (width/2);
}

//returns top global bound y of ball
float Ball::topBound(){
    return ball.getPosition().y - (length/2);
}

//returns bottom global bound y of ball
float Ball::bottomBound(){
    return ball.getPosition().y + (length/2);
}

bool Ball::isLeft(){
    if (velocity < 0)
        return true;
    else
        return false;
}

int Ball::touchedPaddle(Paddle* paddle){
    //1 for hits left paddle
    if (Ball::isLeft() && Ball::leftSide() <= paddle->rightSide() ){
        if  ( Ball::rightSide() >= paddle->leftSide() &&
            ( Ball::topBound() <= paddle->lowerBorder() && Ball::bottomBound() >= paddle->upperBorder() )){
            return 1;
        }
    }
    //2 for hit right paddle
    else if (!Ball::isLeft() && Ball::rightSide() >= paddle->leftSide()){
        if  ( Ball::leftSide() <= paddle->rightSide() &&
            ( Ball::topBound() <= paddle->lowerBorder() && Ball::bottomBound() >= paddle->upperBorder() )){
            return 2;
        }
    }
    //0 for no paddle
    return 0;
}

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
        Left.moves(true);
        Right.moves(false);
        
        ball.shoots();
        ball.drawto(window);
        
        if (ball.touchedPaddle(&Left) == 1){
            ball.changeDirection(1);
        }
        else if (ball.touchedPaddle(&Right) == 2){
            ball.changeDirection(2);
        }
        
        
        
        window.display();
    }
}
