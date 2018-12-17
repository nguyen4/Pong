//
//  Paddle.cpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/14/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#include "Paddle.hpp"
#include "globalVar.h"

Paddle::Paddle(bool left){
    height = 150;
    width = 30;
    dist = 35;
    left_Paddle = left;
    paddle.setSize({width, height});
    paddle.setFillColor(sf::Color::White);
    
    if (left)
    {
        paddle.setOrigin(0, height/2.0f);
        paddle.setPosition(100, SCREEN_HEIGHT/2.0f);
    }
    else
    {
        paddle.setOrigin(width, height/2.0f);
        paddle.setPosition(SCREEN_WIDTH - 100, SCREEN_HEIGHT/2.0f);
    }
}

void Paddle::drawto(sf::RenderWindow &window){
    Paddle::moves();
    window.draw(paddle);
}

void Paddle::moves(){
    
    // handles the keys that moves righr and left paddle
    if (left_Paddle) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && paddle.getPosition().y >= paddle.getOrigin().y)
        {
            paddle.move(0.0f, -dist);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && paddle.getPosition().y <= (SCREEN_HEIGHT - paddle.getOrigin().y))
        {
            paddle.move(0.0f, dist);
        }
    }
    
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && paddle.getPosition().y >= paddle.getOrigin().y)
        {
            paddle.move(0.0f, -dist);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && paddle.getPosition().y <= (SCREEN_HEIGHT - paddle.getOrigin().y))
        {
            paddle.move(0.0f, dist);
        }
    }
}

// gives the global y bound for the top of paddle
float Paddle::upperBorder(){
    return paddle.getPosition().y - height/2;
}

// gives the global y bound for the bottom of paddle
float Paddle::lowerBorder(){
    return paddle.getPosition().y + height/2;
}

// gives the global x bound for the left side of paddle
float Paddle::leftSide(){
    return paddle.getPosition().x - width/2;
}

// gives the global x bound for the right side of paddle
float Paddle::rightSide(){
    return paddle.getPosition().x + width/2;
}

// gives the global x position of paddle
float Paddle::getPosx(){
    return paddle.getPosition().x;
}

// gives the global y position of paddle
float Paddle::getPosy(){
    return paddle.getPosition().y;
}

// gives height of paddle
float Paddle::getHeight(){
    return height;
}

// give width of paddle
float Paddle::getWidth(){
    return width;
}
