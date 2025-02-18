//
// Created by pmi03 on 01.05.2023.
//
#include "BoardTextView.h"
#include <iostream>
#include <ctime>

BoardTextView::BoardTextView(int Width, int Height) {
    srand(time(NULL));

    width = Width;
    height = Height;
    board.resize(board.size() + width*height);

    // oznaczenie pozycji jabłka na planszy
//    int x = rand() % (width-2)+1;
//    int y = rand() % (height-2)+1;
//    board[x + y * width] = 2;

}

void BoardTextView :: debug_display() const{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[y * width + x] == 0) {
                if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                    cout << " W ";  // pole na granicy planszy
                } else {
                    cout << "   ";  // puste pole
                }
            } else if (board[y * width + x] == 1) {
                cout << " 1 ";  // pozycja węża
            } else if (board[y * width + x] == 2) {
                cout << " O ";  // pozycja jedzenia
            } else if (board[y * width + x] == 4) {
                cout << " 1 ";
            }
        }
        cout << endl;
    }
}

int BoardTextView :: getBoardWidth() const
{
    return width;
}

int BoardTextView :: getBoardHeight() const
{
    return height;
}


char BoardTextView ::getFieldInfo(int x, int y) const{
    int width=getBoardWidth();
    int height=getBoardHeight();
    if (board[y * width + x] == 1) { // wąż
        return 'S';
    } else if (board[y * width + x] == 2) { // jabłko
        return 'A';
    } else if (board[y * width + x] == 4) { // Wąż na polu z jablkiem
        return 'S';
    } else if (x == 0 || x == width - 1 || y == 0 || y == height - 1) { // ściana
        return '#';
    } else { // puste pole
        return ' ';
    }

}

void BoardTextView ::display() {
    for (int i = 0; i < getBoardHeight(); i++) {
        for (int j = 0; j < getBoardWidth(); j++) {
           cout << " " << getFieldInfo(j, i) << " ";
        }
        cout << endl;
    }
}