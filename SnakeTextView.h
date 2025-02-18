//
// Created by pmi03 on 02.05.2023.
//

#ifndef SNAKE_SNAKETEXTVIEW_H
#define SNAKE_SNAKETEXTVIEW_H
#include <iostream>
#include <vector>
#include "BoardTextView.h"
#include <SFML/Graphics.hpp>

using namespace std;

enum Direction{UP, RIGHT, LEFT, DOWN};
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum GameMode { EASY, NORMAL, HARD };

class SnakeTextView{
    BoardTextView & board1;
    vector<int> snake;
    int width{};
    int height{};
    sf :: Clock clock;

    Direction direction;  // kierunek poruszania się węża (0 - w górę, 1 - w prawo, 2 - w lewo)

//    int dx{};  // zmiana współrzędnej x w zależności od kierunku
//    int dy{};  // zmiana współrzędnej y w zależności od kierunku

public:
    SnakeTextView(BoardTextView & b);
    void moveStraight();
    void turnRight();
    void turnLeft();
    void goUP();
    void goDOWN();
    bool isEating();
    bool isColliding();
    void growUp();
    GameState getGameState();
    void AppleGenerator();
    void update();
    int score=0;
    GameMode mode;
    int speed;
//    float CurrentTime;
};
#endif //SNAKE_SNAKETEXTVIEW_H
