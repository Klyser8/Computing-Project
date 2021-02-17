#include "Button.h"

Button::Button(sf::Sprite normalSprite, std::string _str, sf::Font font) : normalSprite(normalSprite) {
    state = DEFAULT;
    hoverSprite = normalSprite;
    hoverSprite.setColor(sf::Color::Yellow);
    clickSprite = normalSprite;
    clickSprite.setColor(sf::Color::Black);
    text.setFont(font);
    text.setString(_str);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
}

sf::Text Button::getText() {
    return text;
}

void Button::setText(std::string _str) {
    text.setString(_str);
}

Button::State Button::getState() {
    return Button::state;
}

void Button::setState(Button::State _state) {
    state = _state;
}

bool Button::isHovering(sf::Vector2<float> _mousePos) {
    return getSprite().getGlobalBounds().contains(_mousePos.x, _mousePos.y);
}

Button::Button() {}

sf::Sprite Button::getSprite() {
    switch (state) {
        case DEFAULT:
            return normalSprite;
        case HOVERED:
            return hoverSprite;
        case CLICKED:
            return clickSprite;
    }
}

