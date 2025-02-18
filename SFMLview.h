//
// Created by pmi03 on 03.05.2023.
//

#ifndef SNAKE_SFMLVIEW_H
#define SNAKE_SFMLVIEW_H
#include <SFML/Graphics.hpp>
#include "BoardTextView.h"
#include "SnakeTextView.h"

class SFMLview{
    BoardTextView & board;
    SnakeTextView & snake;
    sf::RectangleShape field;
    sf:: Font font;
    sf::Text scoreText, GameOver, YouWon;

public:
    SFMLview(SnakeTextView & snake1, BoardTextView & board1);
    void draw(sf:: RenderWindow & window);
    void iconChoose(sf::RenderWindow &window, const std::string& filename);
    sf::Text buttonText;
    sf::RectangleShape buttonShape;
    bool isScreen1 = true;
};

#endif //SNAKE_SFMLVIEW_H
