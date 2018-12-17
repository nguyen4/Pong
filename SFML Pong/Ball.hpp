//
//  Ball.hpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/16/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "globalVar.h"
#include "Paddle.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>

class Ball{
public:
    Ball();
    void drawto(sf::RenderWindow &window);
    void changeDirection(int event, Paddle* paddle = NULL);
    float leftSide();
    float rightSide();
    float topBound();
    float bottomBound();
    bool isLeft();
    int touchedPaddle(Paddle* paddle);
    bool touchedWall();
    void reset();
    bool isGameOver();
    
private:
    sf::RectangleShape ball;
    float       length;
    float       width;
    float       run;        // x coordinate
    float       rise;       // y coordinate
    float       angle;      // in degrees
    bool        gameover;
};

#endif /* Ball_hpp */
