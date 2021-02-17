#ifndef SFML_TEST_FINAL_SCREEN_H
#define SFML_TEST_FINAL_SCREEN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../util/SpriteUtil.h"

class Screen {

public:
enum ScreenType {
    MENU,
    GAME,
    WIN,
    LOSS
};

protected:
    sf::RenderWindow& window;
    ScreenType screenType;

public:

    Screen(sf::RenderWindow &window, ScreenType screenType) : window(window), screenType(screenType) {}

    virtual void render() = 0;

    virtual void handleEvents(sf::Event event) = 0;
};

#endif