//
// Created by pmi03 on 06.05.2023.
//

#ifndef SNAKE_OTHERWINDOWS_H
#define SNAKE_OTHERWINDOWS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardTextView.h"
#include "SnakeTextView.h"
#include "SFMLview.h"

class otherWindows{
    BoardTextView & board;
    SnakeTextView & snake;

public:

    sf:: Font font;
    sf::RectangleShape field, buttonShape, buttonEasy, buttonNormal, buttonHard;
    sf::Text buttonText, easyText, normalText, hardText, Snake;
    otherWindows(SnakeTextView & snake1, BoardTextView & board1);
    void drawMenuScreen(sf:: RenderWindow & window);


    bool isScreen1 = true;
};
#endif //SNAKE_OTHERWINDOWS_H
