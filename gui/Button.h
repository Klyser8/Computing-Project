#ifndef SFML_TEST_FINAL_BUTTON_H
#define SFML_TEST_FINAL_BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
    enum State {
        DEFAULT,
        HOVERED,
        CLICKED
    };

private:
    sf::Sprite normalSprite;
    sf::Sprite hoverSprite;
    sf::Sprite clickSprite;

    sf::Text text;
    State state;

public:
    Button(sf::Sprite normalSprite, std::string text, sf::Font font);

    Button();

    bool isHovering(sf::Vector2<float> _mousePos);

    sf::Text getText();
    void setText(std::string _text);

    State getState();
    void setState(State _state);

    sf::Sprite getSprite();
};

#endif