//
//  Ball.cpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/16/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#include "Ball.hpp"

Ball::Ball(){
    length = 30;
    width = 30;
    run = 25;
    rise = 0;
    angle = .80;
    gameover = false;
    ball.setSize({width, length});
    ball.setOrigin(width/2.0f, length/2.0f);
    ball.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    ball.setFillColor(sf::Color::Green);
    
}

void Ball::drawto(sf::RenderWindow &window){
    
    if (Ball::leftWon() || Ball::rightWon()){
        gameover = true;
    }
    
    ball.move(run, rise);
    window.draw(ball);
}

void Ball::changeDirection(int event, Paddle* paddle){
    
    // handles left paddle collision
    if (event == 1){
        float y = ball.getPosition().y - paddle->getPosy();
        float sub_angle = ( angle/ (paddle->getHeight()/2) ) * y;
        rise = sub_angle * abs(run);
        run = fabs(run);
    }
    // handles right paddle collision
    if (event == 2){
        float y = ball.getPosition().y - paddle->getPosy();
        float sub_angle = ( angle/ (paddle->getHeight()/2) ) * y;
        rise = sub_angle * abs(run);
        run = (-1) * run;
    }
    // handles wall collision , reverse the rise variable
    if (event == 3){
        rise = (-1)*rise;
    }
}

// returns left global x bound on ball
float Ball::leftSide(){
    return ball.getPosition().x - (width/2);
}

// returns right global x bound on ball
float Ball::rightSide(){
    return ball.getPosition().x + (width/2);
}

// returns top global y bound on ball
float Ball::topBound(){
    return ball.getPosition().y - (length/2);
}

// returns bottom global y bound on ball
float Ball::bottomBound(){
    return ball.getPosition().y + (length/2);
}

// checks the direction of the ball
bool Ball::isLeft(){
    
    // if run (x coordinate) is negative, then the ball is going left, otherwise it is going right
    if (run < 0)
        return true;
    else
        return false;
}

// checks if the ball hits a paddle
int Ball::touchedPaddle(Paddle* paddle){
    
    // 1 for hits left paddle
    if (Ball::isLeft() && Ball::leftSide() <= paddle->rightSide() + abs(run) ){
        if  ( Ball::rightSide() >= paddle->leftSide() &&
            ( Ball::topBound() <= paddle->lowerBorder() && Ball::bottomBound() >= paddle->upperBorder() )){
            return 1;
            
        }
    }
    // 2 for hits right paddle
    else if (!Ball::isLeft() && Ball::rightSide() >= paddle->leftSide() - abs(run) ){
        if  ( Ball::leftSide() <= paddle->rightSide() &&
            ( Ball::topBound() <= paddle->lowerBorder() && Ball::bottomBound() >= paddle->upperBorder() )){
            return 2;
        }
    }
    // 0 for doesnt hit paddle
    return 0;
}

//checks if the ball goes past right bound
bool Ball::leftWon(){
    if (ball.getPosition().x > SCREEN_WIDTH + width){
        return true;
    }
    return false;
}

//checks if the ball goes past left bound
bool Ball::rightWon(){
    if (ball.getPosition().x < (-1) * (width)){
        return true;
    }
    return false;
}

// checks if ball hits the wall
bool Ball::touchedWall(){
    if (topBound() <= 0 || bottomBound() >= SCREEN_HEIGHT)
        return true;
    
    return false;
}

void Ball::reset(){
    ball.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
    gameover = false;
    rise = 0;
}

bool Ball::isGameOver(){
    return gameover;
}

void Ball::setGameOver(bool isOver = true){
    if (isOver)
        gameover = true;
    else
        gameover = false;
}
