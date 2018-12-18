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
    void    moves();
    void    drawto(sf::RenderWindow &window);
    bool    isLeft();
    void    addOne();
    int     getScore();
    float   upperBorder();
    float   lowerBorder();
    float   leftSide();
    float   rightSide();
    float   getPosx();
    float   getPosy();
    float   getHeight();
    float   getWidth();
    
private:
    sf::RectangleShape  paddle;     //all private variables will be initiated in the constructor
    float               height;
    float               width;
    float               dist;
    bool                left_Paddle;
    int                 score;
    
};

#endif /* Paddle_hpp */
