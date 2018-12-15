//
//  Paddle.hpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/14/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#ifndef Paddle_hpp
#define Paddle_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>

class Paddle {
public:
    Paddle(bool left);
    void moves(bool left);
    void drawto(sf::RenderWindow &window);
    float upperBorder();
    float lowerBorder();
    float leftSide();
    float rightSide();
    float getPosx();
    float getPosy();
    
private:
    sf::RectangleShape  paddle;     //all private variables will be initiated in the constructor
    float               height;
    float               width;
    float               dist;
    
};

#endif /* Paddle_hpp */