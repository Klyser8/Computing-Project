#ifndef SFML_TEST_FINAL_MENUSCREEN_H
#define SFML_TEST_FINAL_MENUSCREEN_H

#include "Screen.h"
#include "../gui/Button.h"

class MenuScreen: public Screen {
private:
    sf::Texture bgTexture;
    sf::Texture titleTexture;
    sf::Sprite bgSprite;
    sf::Sprite titleSprite;

    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;

    sf::Font font;

    Button playButton;

public:

    MenuScreen(sf::RenderWindow& _window);

    ~MenuScreen();

    void render() override;

    void handleEvents(sf::Event event) override;
};

#endif