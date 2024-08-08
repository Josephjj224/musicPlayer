#include "doublelist.hpp"
#include <string>

/*
    SFML - Simple and Fast Multimedia Library
    Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)

    This software is provided 'as-is', without any express or implied warranty.
    In no event will the authors be held liable for any damages arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it freely,

    subject to the following restrictions:

    1. The origin of this software must not be misrepresented;
       you must not claim that you wrote the original software.
       If you use this software in a product, an acknowledgment
       in the product documentation would be appreciated but is not required.

    2. Altered source versions must be plainly marked as such,
       and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 1000), "Music Player");
    sf::Texture coverTexture;
    if (!coverTexture.loadFromFile("recourse/music.png")) {
        cerr << "Failed to load image" << endl;
        return -1;
    }

    sf::Sprite coverSprite;


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
    playlist.addTrack("Bohemian Rhapsody", "Queen", "recourse/Queen.jpg");
    playlist.addTrack("1989", "Taylor Swift", "recourse/taylor.jpeg");
    playlist.addTrack("Too Sweet", "Hozier", "recourse/hozier.jpeg");
    if (!coverTexture.loadFromFile(playlist.get()->album)) {
        cerr << "Failed to load initial image" << endl;
        return -1;
    }

    sf::RectangleShape nextButton(sf::Vector2f(150, 50));
    nextButton.setFillColor(sf::Color::White);
    nextButton.setPosition(600, 700); 

    sf::Text nextButtonText;
    nextButtonText.setFont(font);
    nextButtonText.setString("->");
    nextButtonText.setCharacterSize(24);
    nextButtonText.setFillColor(sf::Color::Black); 
    nextButtonText.setPosition(
        nextButton.getPosition().x + 30, 
        nextButton.getPosition().y + 10
    );

    sf::RectangleShape prevButton(sf::Vector2f(150, 50));
    prevButton.setFillColor(sf::Color::White);
    prevButton.setPosition(50, 700); 

    sf::Text prevButtonText;
    prevButtonText.setFont(font);
    prevButtonText.setString("<-");
    prevButtonText.setCharacterSize(24);
    prevButtonText.setFillColor(sf::Color::Black); 
    prevButtonText.setPosition(
        prevButton.getPosition().x + 10, 
        prevButton.getPosition().y + 10
    );

    

    Node* currentTrack = playlist.get();
    text.setString(currentTrack->artist + " - " + currentTrack->title);
    if (!coverTexture.loadFromFile(currentTrack->album)) {
        cerr << "Failed to load image: " << currentTrack->album << endl;
    } 
    else{
        coverSprite.setTexture(coverTexture);
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
       
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (nextButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                         if(currentTrack->next != nullptr)
                        {
                            currentTrack = currentTrack->next;
                        }
                        if(currentTrack->next == nullptr)
                        {
                            playlist.reverse();
                        }
                    } 
                    if (prevButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if(currentTrack->prev != nullptr)
                        {
                            currentTrack = currentTrack->prev;
                        }
                        if(currentTrack->prev == nullptr)
                        {
                            playlist.reverse();
                        }
                    }
                
                    if(currentTrack){
                        string artist = currentTrack->artist;
                        string title = currentTrack->title;
                        string album = currentTrack->album;
                        text.setString(artist + " - " + title);
                    }

                    if (!coverTexture.loadFromFile(currentTrack->album)) {
                        cerr << "Failed to load image: " << currentTrack->album << endl;
                    } else {
                        coverSprite.setTexture(coverTexture);
                    }
                

                
                }
            }

        }

        window.clear();
        window.draw(coverSprite);
        window.draw(text);
        window.draw(nextButton);
        window.draw(nextButtonText);
        window.draw(prevButton);
        window.draw(prevButtonText);
        window.display();
    }

    return 0;
}
