//
// Created by pmi03 on 06.05.2023.
//
#include "otherWindows.h"

using namespace std;

otherWindows ::otherWindows(SnakeTextView &snake1, BoardTextView &board1) : snake(snake1), board(board1) {
    field = sf::RectangleShape (sf::Vector2f(40, 40));
    field.setFillColor(sf::Color(0, 0, 0));
    font= sf::Font();
    font.loadFromFile("../Textures/WockeFunky.ttf");

    Snake.setFont(font);
    Snake.setString("SNAKE");
    Snake.setCharacterSize(100);
    Snake.setFillColor(sf::Color(0, 102, 51));
    Snake.setOutlineColor(sf::Color::Black);
    Snake.setOutlineThickness(5);
    Snake.setPosition(310, 70);

    // Ustawienie pozycji i wymiarów przycisku
    buttonShape.setPosition(340, 340);
    buttonShape.setSize(sf::Vector2f(200, 75));
    buttonShape.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    buttonShape.setOutlineColor(sf::Color::Black);
    buttonShape.setOutlineThickness(5);
    // Ustawienie tekstu na przycisku
    buttonText.setFont(font);
    buttonText.setString("Play");
    buttonText.setCharacterSize(50); // Możesz dostosować rozmiar czcionki
    buttonText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki
    // Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    buttonText.setPosition(340 + 200 / 2, 340 + 75 / 2);
    buttonText.setOutlineColor(sf::Color::Black);
    buttonText.setOutlineThickness(5);

    //EASY
    buttonEasy.setPosition(100, 540);
    buttonEasy.setSize(sf::Vector2f(150, 50));
    buttonEasy.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    buttonEasy.setOutlineColor(sf::Color::Black);
    buttonEasy.setOutlineThickness(5);

    easyText.setFont(font);
    easyText.setString("Easy");
    easyText.setCharacterSize(30); // Możesz dostosować rozmiar czcionki
    easyText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki

    sf::FloatRect easyTextBound = easyText.getLocalBounds();
    easyText.setOrigin(easyTextBound.left + easyTextBound.width / 2, easyTextBound.top + easyTextBound.height / 2);
    easyText.setPosition(100 + 150 / 2, 540 + 50 / 2);
    easyText.setOutlineColor(sf::Color::Black);
    easyText.setOutlineThickness(5);


    //NORMAL
    buttonNormal.setPosition(362, 540);
    buttonNormal.setSize(sf::Vector2f(150, 50));
    buttonNormal.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    buttonNormal.setOutlineColor(sf::Color::Black);
    buttonNormal.setOutlineThickness(5);
    // Ustawienie tekstu na przycisku
    normalText.setFont(font);
    normalText.setString("Normal");
    normalText.setCharacterSize(30); // Możesz dostosować rozmiar czcionki
    normalText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki

    // Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect normalTextBound = buttonText.getLocalBounds();
    normalText.setOrigin(normalTextBound.left + normalTextBound.width / 2, normalTextBound.top + normalTextBound.height / 2);
    normalText.setPosition(362 + 150 / 2, 540 + 75 / 2);
    normalText.setOutlineColor(sf::Color::Black);
    normalText.setOutlineThickness(5);


    //HARD
    buttonHard.setPosition(620, 540);
    buttonHard.setSize(sf::Vector2f(150, 50));
    buttonHard.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    buttonHard.setOutlineColor(sf::Color::Black);
    buttonHard.setOutlineThickness(5);
    // Ustawienie tekstu na przycisku
    hardText.setFont(font);
    hardText.setString("Hard");
    hardText.setCharacterSize(30); // Możesz dostosować rozmiar czcionki
    hardText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki

    // Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect hardTextBound = buttonText.getLocalBounds();
    hardText.setOrigin(hardTextBound.left + hardTextBound.width / 2, hardTextBound.top + hardTextBound.height / 2);
    hardText.setPosition(620 + 175 / 2, 540 + 75 / 2);
    hardText.setOutlineColor(sf::Color::Black);
    hardText.setOutlineThickness(5);

}

void otherWindows ::drawMenuScreen(sf:: RenderWindow & window) {

    sf :: Texture icon;
    icon.loadFromFile("../Textures/MenuWall.png");
    sf::Sprite sprite;
    sprite.setTexture(icon);
    sprite.setScale(0.155f, 0.155f);

    int repeatX = window.getSize().x / 38;
    int repeatY = window.getSize().y / 38;

    for (int y = 0; y < repeatY; ++y)
    {
        for (int x = 0; x < repeatX; ++x)
        {
            // Oblicz pozycję sprite'a na ekranie
            float posX = x*40;
            float posY = y*40;

            sprite.setPosition(posX, posY);
            window.draw(sprite);
        }
    }

    window.draw(buttonShape);
    window.draw(buttonText);
    window.draw(buttonEasy);
    window.draw(easyText);
    window.draw(buttonNormal);
    window.draw(normalText);
    window.draw(buttonHard);
    window.draw(hardText);
    window.draw(Snake);
}
