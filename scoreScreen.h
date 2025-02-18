//
// Created by pmi03 on 07.05.2023.
//

#ifndef SNAKE_SCORESCREEN_H
#define SNAKE_SCORESCREEN_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardTextView.h"
#include "SnakeTextView.h"
#include "otherWindows.h"
#include "SFMLview.h"
#include <string>
#include "algorithm"

struct Player {
    std::string Nick;
    int Score;
};

class scoreScreen{

    BoardTextView & board;
    SnakeTextView & snake;
    sf::Text snakeText, scoreText, numbers, nickNumbers, playersScores;
    sf::Font font;


public:
    scoreScreen(BoardTextView & board1, SnakeTextView & snake1);

    void inputNickname(sf:: RenderWindow & window);
    void drawScoreScreen(sf:: RenderWindow & window);
    void dataStuff(sf:: RenderWindow & window);
    //void sort(std::vector<Player>& players, int index);

    sf:: Text inputText, promptText, buttonText, autorText1, autorText2, quitText;
    sf::RectangleShape menuButton, quitButton;
    string lastNickname;
};

#endif //SNAKE_SCORESCREEN_H
