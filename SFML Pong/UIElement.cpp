//
//  UIElement.cpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/18/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#include "UIElement.hpp"
#include <string.h>

UIElement::UIElement(){
    Left_Score = 0;
    Right_Score = 0;
    if (!font.loadFromFile("../lib/sh-pinscher/SHPinscher-Regular.oft"))
    {
        // error...
        printf("could not find or use font 'sh-pinscher'.");
    }
    
    //initializing score number characteristics
    leftScore.setFont(font);
    rightScore.setFont(font);
    leftScore.setCharacterSize(25);
    rightScore.setCharacterSize(25);
    leftScore.setFillColor(sf::Color::White);
    rightScore.setFillColor(sf::Color::White);
    //leftScore.setPosition(0 + leftScore.getLocalBounds().width, 200);
}

void UIElement::updateScore(Paddle* paddle){
    if (paddle->isLeft()){
        Left_Score += 1;
        leftScore.setString(std::to_string(Left_Score));
    }
    else{
        Right_Score += 1;
        rightScore.setString(std::to_string(Right_Score));
    }
}

void UIElement::drawto(sf::RenderWindow &window){
    window.draw(leftScore);
    window.draw(rightScore);
}
