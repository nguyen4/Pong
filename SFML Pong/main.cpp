#include <SFML/Graphics.hpp>

#include <iostream>
#include "globalVar.h"
#include "Paddle.hpp"
#include <math.h>

class Ball{
public:
    Ball();
    void drawto(sf::RenderWindow &window);
    void changeDirection(int event, Paddle* paddle);
    float leftSide();
    float rightSide();
    float topBound();
    float bottomBound();
    bool isLeft();
    int touchedPaddle(Paddle* paddle);
    bool touchedWall();
    
private:
    sf::RectangleShape ball;
    float       length;
    float       width;
    float       run;
    float       rise;
    float       angle;  //in degrees
};

Ball::Ball(){
    length = 35;
    width = 35;
    run = 7;
    rise = 0;
    angle = .75;
    ball.setSize({width, length});
    ball.setOrigin(width/2.0f, length/2.0f);
    ball.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    ball.setFillColor(sf::Color::Green);

}

void Ball::drawto(sf::RenderWindow &window){
    ball.move(run, rise);
    window.draw(ball);
}

void Ball::changeDirection(int event = 3, Paddle* paddle = NULL){ //might change the logic of change direction;
    if (event == 1){
        float y = ball.getPosition().y - paddle->getPosy();
        float sub_angle = ( angle/ (paddle->getHeight()/2) ) * y;
        rise = sub_angle * abs(run);
        run = fabs(run);
    }
    if (event == 2){
        float y = ball.getPosition().y - paddle->getPosy();
        float sub_angle = ( angle/ (paddle->getHeight()/2) ) * y;
        rise = sub_angle * abs(run);
        run = (-1) * run;
    }
    if (event == 3){
        rise = (-1)*rise;
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
    if (run < 0)
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

bool Ball::touchedWall(){
    if (topBound() <= 0 || bottomBound() >= SCREEN_HEIGHT)
        return true;

    return false;
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
        
        ball.drawto(window);
        
        if (ball.touchedPaddle(&Left) == 1){
            ball.changeDirection(1, &Left);
        }
        else if (ball.touchedPaddle(&Right) == 2){
            ball.changeDirection(2, &Right);
        }
        else if (ball.touchedWall()){
            ball.changeDirection();
        }
        
        window.display();
    }
}
