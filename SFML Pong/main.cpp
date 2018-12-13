#include <SFML/Graphics.hpp>

#include <iostream>
#include "globalVar.h"

class Paddle {
public:
    Paddle(bool left);
    void moves(bool left);
    void drawto(sf::RenderWindow &window);
    
private:
    sf::RectangleShape  paddle;
    float               height;
    float               width;
    float               dist;

};

Paddle::Paddle(bool left){
    
    height = SCREEN_HEIGHT/5.0f;
    width = SCREEN_WIDTH/40.0f;
    dist = 0.8;
    paddle.setSize({width, height});
    paddle.setFillColor(sf::Color::White);
    
    if (left)
    {
        paddle.setOrigin(0, height/2.0f);
        paddle.setPosition(0, SCREEN_HEIGHT/2.0f);
    }
    else
    {
        paddle.setOrigin(width, height/2.0f);
        paddle.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT/2.0f);
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

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Pong");
    Paddle Left(true);
    Paddle Right(false);
    
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
        
        
        window.display();
    }
}
