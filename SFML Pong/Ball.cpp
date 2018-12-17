//
//  Ball.cpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/16/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#include "Ball.hpp"

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
    if (gameover){
        Ball::reset();
    }
    
    ball.move(run, rise);
    window.draw(ball);
}

void Ball::changeDirection(int event, Paddle* paddle){ //might change the logic of change direction;
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

void Ball::reset(){
    ball.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    rise = 0;
    run = 7;
}
