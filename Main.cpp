#include <string>
#include "screens/Screen.h"
#include "screens/MenuScreen.h"

const std::string GAME_VERSION = "0.0.1";
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

class GameClock {
private:
    sf::Clock _clock;

public:
    GameClock() {
        std::cout << "Game clock started!" << std::endl;
    }

    ~GameClock() {
        std::cout << "Game clock stopped!" << std::endl;
    }

    int getTimeElapsed() {
        return _clock.getElapsedTime().asMilliseconds();
    }

    void resetClock() {
        _clock.restart();
    }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Azuria " + GAME_VERSION);
    window.setVerticalSyncEnabled(true);
    GameClock clock;
    std::unique_ptr<Screen> _currentScreen = std::make_unique<MenuScreen>(window);

    //When the window is open
    while (window.isOpen())
    {
        sf::Event event;
        sf::View view = window.getDefaultView();
        //Process events.
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        clock.resetClock();
                    }
                    break;

/*                case sf::Event::Resized:
                    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
                    view.setSize(window.getSize().x, window.getSize().y);
                    window.setView(view);
                    break;*/
                default:
                    break;
            }
            _currentScreen->handleEvents(event);
        }

        window.clear(sf::Color::Black);
        _currentScreen->render();
        window.display();
    }

    return 0;
}