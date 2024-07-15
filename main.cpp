#include "doublelist.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// int main() {
//     sf::RenderWindow window(sf::VideoMode(1000, 800), "Music Player");
//     sf::Texture coverTexture;
//     if (!coverTexture.loadFromFile("/Users/jaeyunjeong/Desktop/image.jpg")) {
//         return -1;
//     }

//     sf::Sprite coverSprite;
//     coverSprite.setTexture(coverTexture);

   
//    sf::Font font;
//    if (!font.loadFromFile("/Users/jaeyunjeong/Desktop/SwanseaBoldItalic-p3Dv.ttf")) {
//         std::cerr << "Failed to load font" << std::endl;
//         return -1;
//     }
//     sf::Text text;
//     text.setFont(font);
//     text.setCharacterSize(24);
//     text.setFillColor(sf::Color::White);

//     Playlist playlist;
//     playlist.addTrack("Song Title", "Artist Name", "Album Name");

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         // 현재 재생 중인 트랙 정보를 텍스트로 설정하고 표시
//         if (playlist.get()) {
//             text.setString(playlist.get()->album + " - " + playlist.get()->artist);
//             window.draw(text);
//         }

//         window.display();
//     }

//     return 0;
// }
int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Music Player");
    sf::Texture coverTexture;
    if (!coverTexture.loadFromFile("recourse/image.jpg")) {
        cerr << "Failed to load image" << endl;
        return -1;
    }

    sf::Sprite coverSprite;
    coverSprite.setTexture(coverTexture);
    coverSprite.setPosition(10, 50);  // 위치 지정

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
    float textYPosition = coverSprite.getPosition().y + spriteBounds.height + 10;  // 스프라이트 하단에 여백 추가
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
        // 현재 재생 중인 트랙 정보를 텍스트로 설정하고 표시
        if (playlist.get() != nullptr) {
            string album = playlist.get()->album; 
            string title = playlist.get()->title;
            text.setString(album + "-" + title);
            window.draw(text);
        }
        window.draw(text);
        window.draw(coverSprite);  // 스프라이트 그리기
        window.display();
    }

    return 0;
}