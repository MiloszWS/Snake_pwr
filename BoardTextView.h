//
// Created by pmi03 on 01.05.2023.
//

#ifndef SNAKE_BOARDTEXTVIEW_H
#define SNAKE_BOARDTEXTVIEW_H
#include <iostream>
#include <vector>

using namespace std;

class BoardTextView{
int width;
int height;
public:
    vector<int> board;
    BoardTextView(int width, int height);
    void debug_display() const;
    int getBoardHeight() const;
    int getBoardWidth() const;
//    bool hasApple(const vector<int>& board, int width, int x, int y) const;
//    bool isWall(const vector<int>& board, int width, int x, int y) const;
//    bool isSnake(const vector<int>& board, int width, int x, int y) const;
    char getFieldInfo(int x, int y) const;
    void display();

};
#endif //SNAKE_BOARDTEXTVIEW_H
