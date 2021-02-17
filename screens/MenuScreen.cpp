#include "MenuScreen.h"

MenuScreen::MenuScreen(sf::RenderWindow &_window) : Screen(_window, Screen::MENU) {
    if (!bgTexture.loadFromFile("assets/menu.png")) {
        std::cout << "Could not load menu.png!" << std::endl;
    }
    if (!titleTexture.loadFromFile("assets/azuria.png")) {
        std::cout << "Could not load azuria.png!" << std::endl;
    }
    if (!buttonTexture.loadFromFile("assets/button.png")) {
        std::cout << "Could not load button.png!" << std::endl;
    }
    if (!font.loadFromFile("assets/font/basic-celestial.ttf")) {
        std::cout << "Could not load basic-celestial.ttf!" << std::endl;
    }
    bgSprite.setTexture(bgTexture);
    titleSprite.setTexture(titleTexture);
    buttonSprite.setTexture(buttonTexture);
    float scaleFactor = calculateScaleFactor(window.getSize().x, bgTexture.getSize().x);
    bgSprite.setScale(scaleFactor, scaleFactor);
    titleSprite.setPosition((window.getSize().x / 2.f) - (titleTexture.getSize().x / 2.f),
                            (window.getSize().y / 5.f) - (titleTexture.getSize().y / 2.f));

    buttonSprite.setScale(2.f, 2.f);
    buttonSprite.setPosition((window.getSize().x / 2.f) -
                                (buttonTexture.getSize().x / 2.f * buttonSprite.getScale().x),
                             (window.getSize().y / 2.f) -
                             (buttonTexture.getSize().y / 2.f * buttonSprite.getScale().y));
    playButton = Button(buttonSprite, "Play", font);
    std::cout << "But X1: " << playButton.getSprite().getPosition().x << "; But Y1: "
              << playButton.getSprite().getPosition().y
              << "\tBut X2: " << playButton.getSprite().getPosition().x
              + playButton.getSprite().getTexture()->getSize().x
              << "; But Y2: " << playButton.getSprite().getPosition().y
              + playButton.getSprite().getTexture()->getSize().y << std::endl;
}

void MenuScreen::render()  {
    window.draw(bgSprite);
    window.draw(titleSprite);
    window.draw(playButton.getSprite());
    window.draw(playButton.getText());
}

MenuScreen::~MenuScreen() {

}

void MenuScreen::handleEvents(sf::Event event) {
    if (event.type == event.MouseMoved) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (playButton.isHovering(mousePos)) {
            if (playButton.getState() != Button::State::DEFAULT) return;
            std::cout << "Mouse X: " << mousePos.x << "; Mouse Y: " << mousePos.y << std::endl;
            playButton.setState(Button::State::HOVERED);
        } else if (playButton.getState() == Button::State::HOVERED) {
            playButton.setState(Button::State::DEFAULT);
        }
    }
}
