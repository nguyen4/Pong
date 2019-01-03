//
//  UIElement.hpp
//  SFML Pong
//
//  Created by Tom Nguyen on 12/18/18.
//  Copyright © 2018 Tom Nguyen. All rights reserved.
//

#ifndef UIElement_hpp
#define UIElement_hpp

#include <stdio.h>
#include "Paddle.hpp"

class UIElement {
public:
    UIElement();
    void updateScore(Paddle* paddle);
    void drawto(sf::RenderWindow &window);
private:
    int Left_Score;
    int Right_Score;
    sf::Text leftScore, rightScore;
    sf::Font font;
};


#endif /* UIElement_hpp */
