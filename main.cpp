#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

struct Button {
public:
    sf::Text text;
    sf::RectangleShape rect;

    Button(int x, int y, int w, int h, sf::Font& font, unsigned int size, const std::string& string) {
        rect.setPosition(x,y);
        rect.setSize({w,h});
        
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(sf::Color::Black);
        text.setString(string);

        auto rect = text.getLocalBounds();
        text.setOrigin(rect.width/2,rect.height/2);
        text.setPosition(x+w/2,y+h/2);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(rect);
        window.draw(text);
    }
    bool checkClicked(sf::Vector2i pos) {
        return rect.getGlobalBounds().contains({pos.x,pos.y});
    }
    void setScale(sf::Vector2f scale) {
        rect.setScale(scale);
        rect.setPosition(rect.getPosition().x*scale.x,rect.getPosition().y*scale.y);
        text.setScale(scale);
        text.setPosition(text.getPosition().x*scale.x,text.getPosition().y*scale.y);
        auto rect = text.getLocalBounds();
        text.setOrigin(rect.width/2,rect.height/2);
    }
};

class Game {
public:
    Game(unsigned int width, unsigned int height) {
        video_mode = sf::VideoMode(width,height);
        game_window.create(video_mode, "Color Coded", sf::Style::Fullscreen);

        // load all assets for the menu here
        if (!default_font.loadFromFile("../assets/GameKidAdventure.ttf")) {
            throw std::runtime_error("default font could not load!");
        }
    };

    int run() {
        Button quit{0,0,100,100,default_font,20,"quit"};
        sf::Event event;
        while (game_window.isOpen()) {
            while (game_window.pollEvent(event))  {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (quit.checkClicked(sf::Mouse::getPosition())) {
                        game_window.close();
                        break;
                    }
                }
            }

            game_window.clear();

            quit.draw(game_window);

            game_window.display();
        }
    }

private:
    sf::VideoMode video_mode;
    sf::RenderWindow game_window;

    sf::Font default_font;

    void load_game_assets() {}

    void game() {}
};

int main() {
    Game game(1920,1080);

    return game.run();
}