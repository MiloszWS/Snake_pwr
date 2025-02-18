//
// Created by pmi03 on 04.05.2023.
//

#ifndef SNAKE_SFMLCONTROLLER_H
#define SNAKE_SFMLCONTROLLER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardTextView.h"
#include "SnakeTextView.h"
#include "otherWindows.h"
#include "SFMLview.h"
#include "scoreScreen.h"



class SFMLcontroller{
public:
    sf::Event event;
    SnakeTextView& snake;
    SFMLview& view;
    otherWindows & screen;
    scoreScreen & scoreSc;
    SFMLcontroller(SnakeTextView& snake, SFMLview & view, otherWindows & screen1, scoreScreen & scoreSc1);
    void play();

};

#endif //SNAKE_SFMLCONTROLLER_H
