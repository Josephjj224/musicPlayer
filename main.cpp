#include "doublelist.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Music Player");
    sf::Texture coverTexture;
    if (!coverTexture.loadFromFile("recourse/image.jpg")) {
        cerr << "Failed to load image" << endl;
        return -1;
    }

    sf::Sprite coverSprite;
    coverSprite.setTexture(coverTexture);
    coverSprite.setPosition(10, 50);  

    sf::Font font;
    if (!font.loadFromFile("recourse/font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    } else {
        std::cout << "Font loaded successfully" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString("");
    text.setFillColor(sf::Color::White);
    sf::FloatRect spriteBounds = coverSprite.getLocalBounds();
    float textYPosition = coverSprite.getPosition().y + spriteBounds.height + 10;  
    text.setPosition(10, textYPosition); 
    
    Playlist playlist;
    playlist.addTrack("HowSweet", "NewJeans", "NewJeans");
    playlist.printList();
    cout << playlist.get()->album;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); 
        if (playlist.get() != nullptr) {
            string album = playlist.get()->album; 
            string title = playlist.get()->title;
            text.setString(album + "-" + title);
            window.draw(text);
        }
        window.draw(text);
        window.draw(coverSprite);   
        window.display();
    }

    return 0;
}