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
    
    height = 250;
    width = 30;
    dist = 3;
    paddle.setSize({width, height});
    paddle.setFillColor(sf::Color::White);
    
    if (left)
    {
        paddle.setOrigin(0, height/2.0f);
        paddle.setPosition(20, SCREEN_HEIGHT/2.0f);
    }
    else
    {
        paddle.setOrigin(width, height/2.0f);
        paddle.setPosition(SCREEN_WIDTH - 20, SCREEN_HEIGHT/2.0f);
    }
}

void Paddle::drawto(sf::RenderWindow &window){
    window.draw(paddle);
}

void Paddle::moves(bool left){
    
    if (left) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && paddle.getPosition().y >= paddle.getOrigin().y)
        {
            paddle.move(0.0f, -dist);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && paddle.getPosition().y <= (SCREEN_HEIGHT - paddle.getOrigin().y))
        {
            paddle.move(0.0f, dist);
        }
        printf("Left pos: %f\n",paddle.getPosition().y);
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
        printf("Right pos: %f\n",paddle.getPosition().y);
    }
}

float Paddle::upperBorder(){
    return paddle.getPosition().y - height/2;
}

float Paddle::lowerBorder(){
    return paddle.getPosition().y + height/2;
}

float Paddle::leftSide(){
    return paddle.getPosition().x - width/2;
}

float Paddle::rightSide(){
    return paddle.getPosition().x + width/2;
}

float Paddle::getPosx(){
    return paddle.getPosition().x;
}

float Paddle::getPosy(){
    return paddle.getPosition().y;
}
