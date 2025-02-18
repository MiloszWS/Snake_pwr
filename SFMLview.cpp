//
// Created by pmi03 on 03.05.2023.
//

#include "SFMLview.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <synchapi.h>

using namespace std;

SFMLview ::SFMLview(SnakeTextView &snake1, BoardTextView & board1) :snake(snake1), board(board1){

    field = sf::RectangleShape (sf::Vector2f(40, 40));
    field.setFillColor(sf::Color(0, 0, 0));
    font= sf::Font();
    font.loadFromFile("../Textures/WockeFunky.ttf");

    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(5);


    GameOver=sf::Text("GAME  OVER", font, 75);
    GameOver.setFillColor(sf::Color::Red);
    GameOver.setOutlineColor(sf::Color::Black);
    GameOver.setOutlineThickness(5);
    GameOver.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = GameOver.getLocalBounds();
    GameOver.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    YouWon=sf::Text("YOU WON!", font, 75);
    YouWon.setFillColor(sf::Color::Cyan);
    YouWon.setOutlineColor(sf::Color::Black);
    YouWon.setOutlineThickness(5);
    YouWon.setStyle(sf::Text::Bold);
    YouWon.getLocalBounds();
    YouWon.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    // Ustawienie pozycji i wymiarów przycisku
    buttonShape.setPosition(250, 700);
    buttonShape.setSize(sf::Vector2f(400, 75));
    buttonShape.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    buttonShape.setOutlineColor(sf::Color::Black);
    buttonShape.setOutlineThickness(5);
    // Ustawienie tekstu na przycisku
    buttonText.setFont(font);
    buttonText.setString("Check Score");
    buttonText.setCharacterSize(50); // Możesz dostosować rozmiar czcionki
    buttonText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki
    // Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    buttonText.setPosition(250 + 400 / 2, 700 + 75 / 2);
    buttonText.setOutlineColor(sf::Color::Black);
    buttonText.setOutlineThickness(5);
}

void SFMLview:: iconChoose(sf::RenderWindow &window, const std::string& filename){
    sf :: Texture icon;
    icon.loadFromFile(filename);
    sf::Sprite sprite;
    sprite.setTexture(icon);
    sprite.setScale(0.155f, 0.155f);
    sprite.setPosition(field.getPosition().x + (field.getSize().x - sprite.getGlobalBounds().width) / 2,
                       field.getPosition().y + (field.getSize().y - sprite.getGlobalBounds().height) / 2);
   // text.setPosition(sf::Vector2f(window.getSize().x / 2.0f, 40.0f));
    window.draw(field);
    window.draw(sprite);
   // window.draw(text);
}

void SFMLview ::draw(sf::RenderWindow &window) {
    sf::Texture EmptyField;
    if (!EmptyField.loadFromFile("../Textures/Grass.png")) {
        std::cout << "Error! EmptyField texture can't be loaded.\n";
    }
    int boardWidth = board.getBoardWidth();
    int boardHeight = board.getBoardHeight();
    int fieldSize = 40; // rozmiar pojedynczego pola
    int boardWidthPixels = boardWidth * fieldSize;
    int boardHeightPixels = boardHeight * fieldSize;

    // obliczamy pozycję lewego górnego rogu planszy
    int boardLeft = (window.getSize().x - boardWidthPixels) / 2;
    int boardTop = (window.getSize().y - boardHeightPixels) / 2;

    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            int x = boardLeft + i * fieldSize;
            int y = boardTop + 20 + j * fieldSize;
            field.setPosition(x, y);

            if (board.getFieldInfo(i, j) == 'S') {
                iconChoose(window, "../Textures/Body.png");
            } else if (board.getFieldInfo(i, j) == 'A') {
                iconChoose(window, "../Textures/Apple.png");
            } else if (board.getFieldInfo(i, j) == '#') {
                iconChoose(window, "../Textures/Wall.png");
            } else if (board.getFieldInfo(i, j) == ' ') {
                iconChoose(window, "../Textures/Grass.png");
            }
        }
    }

    std::string scoreStr = "Score: " + std::to_string(snake.score);
    scoreText.setString(scoreStr);
    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setOrigin(textRect.left + textRect.width, textRect.top);
    scoreText.setPosition(window.getSize().x - 20, 20);
    window.draw(scoreText);

    if (snake.getGameState() == FINISHED_LOSS) {
        GameOver.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
        window.draw(GameOver);
        window.draw(buttonShape);
        window.draw(buttonText);
    } else if (snake.getGameState()== FINISHED_WIN){
        YouWon.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y/2.0f));
        window.draw(YouWon);
        window.draw(buttonShape);
        window.draw(buttonText);
    }
}

