//
// Created by pmi03 on 02.05.2023.
//
#include "SnakeTextView.h"
#include <synchapi.h>
#include <chrono>
#include <thread>

SnakeTextView :: SnakeTextView(BoardTextView &board2) :board1(board2){

    int x = board1.getBoardWidth() / 2;
    int y = board1.getBoardHeight() / 2;
    int head = y * board1.getBoardWidth() + x;
    snake.push_back(head);

    // oznaczenie pozycji węża na planszy
    for (int i = 0; i < snake.size(); i++) {
        board1.board[snake[i]] = 1;
        board1.board[snake[i]+2] = 2;
    }
    if (mode==EASY) speed=100;
    if (mode==NORMAL) speed=50;
    if (mode==HARD) speed=10;
}

void SnakeTextView::moveStraight() {

//    if (CurrentTime < speed)
//    {
//        CurrentTime += clock.restart().asMilliseconds();
//    }
//    else
//    {
        // zapisanie pozycji głowy węża
        int head = snake.front();
        // usunięcie pozycji ogona węża
        int tail = snake.back();
        snake.pop_back();
        board1.board[tail] = 0;
        // dodanie nowej pozycji głowy węża z uwzględnieniem kierunku poruszania się
        switch (direction) {
            case UP:
                head -= board1.getBoardWidth();
                break;
            case RIGHT:
                head += 1;
                break;
            case LEFT:
                head -= 1;
                break;
            case DOWN:
                head += board1.getBoardWidth();
                break;
        }
        // sprawdzenie, czy wąż wjechał na pole z jabłkiem
        if (board1.board[head] == 2) {
            // zmiana wartości pola na 4
            board1.board[head] = 4;
        } else {
            // ustawienie wartości pola na 1
            board1.board[head] = 1;
        }
        snake.insert(snake.begin(), head);
   // }

//    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}


void SnakeTextView :: turnRight() {
    if (direction!=LEFT) direction = RIGHT;
}
void SnakeTextView :: turnLeft() {
    if(direction!=RIGHT) direction = LEFT;
}

void SnakeTextView :: goUP() {
    if(direction!=DOWN) direction = UP;
}

void SnakeTextView :: goDOWN() {
    if(direction!=UP) direction = DOWN;
}

bool SnakeTextView::isEating() {
    int head = snake.front();
    if (board1.board[head] == 4) return true;
    else return false;
}

bool SnakeTextView::isColliding() {
    // pobierz pozycję głowy węża
    int head = snake.front();
    // sprawdź, czy pozycja głowy pokrywa się z którąś z pozycji ciała węża
    for (int i = 1; i < snake.size(); i++) {
        if (head == snake[i]) {
            return true;
        }
    }
    // sprawdź, czy pozycja głowy węża wychodzi poza planszę
    int x = head % board1.getBoardWidth();
    int y = head / board1.getBoardWidth();
    if (x < 1 || x >= board1.getBoardWidth()-1 || y < 1 || y >= board1.getBoardHeight()-1) {
        return true;
    }
    return false;
}


void SnakeTextView::growUp() {
    // pobranie pozycji ostatniego elementu węża (ogona)
    int tail = snake.back();
    // pobranie pozycji przedostatniego elementu węża
    int new_tail = snake[snake.size() - 2];
    // obliczenie pozycji nowego elementu węża, będącego przed nowym ogonem
    int new_part;
    switch (direction) {
        case UP:
            new_part = tail + board1.getBoardWidth();
            break;
        case DOWN:
            new_part = tail - board1.getBoardWidth();
            break;
        case LEFT:
            new_part = tail + 1;
            break;
        case RIGHT:
            new_part = tail - 1;
            break;
    }

    int grow_amount; // domyślnie wąż rośnie o 2 pola
    if (mode==EASY) {
        grow_amount = 1; // przy trudności HARD wąż rośnie o 3 pola
    } else if (mode==NORMAL) {
        grow_amount = 2; // przy trudności HARD wąż rośnie o 3 pola
    } else if (mode==HARD) {
        grow_amount = 3; // przy trudności HARD wąż rośnie o 3 pola
    }

    // dodanie nowych elementów do węża
    for (int i = 0; i < grow_amount; i++) {
        snake.push_back(new_part);
        board1.board[new_part] = 1;
        // obliczenie pozycji kolejnego elementu
        switch (direction) {
            case UP:
                new_part += board1.getBoardWidth();
                break;
            case DOWN:
                new_part -= board1.getBoardWidth();
                break;
            case LEFT:
                new_part += 1;
                break;
            case RIGHT:
                new_part -= 1;
                break;
        }
    }
}
//void SnakeTextView::growUp() {
//    // pobranie pozycji ostatniego elementu węża (ogona)
//    int tail = snake.back();
//    // pobranie pozycji przedostatniego elementu węża
//    int new_tail = snake[snake.size() - 2];
//    // obliczenie pozycji nowego elementu węża, będącego przed nowym ogonem
//    int new_part;
//    switch (direction) {
//        case UP:
//            new_part = tail + board1.getBoardWidth();
//            break;
//        case DOWN:
//            new_part = tail - board1.getBoardWidth();
//            break;
//        case LEFT:
//            new_part = tail + 1;
//            break;
//        case RIGHT:
//            new_part = tail - 1;
//            break;
//    }
//    // dodanie nowego elementu do węża
//    snake.push_back(new_part);
//    board1.board[new_part] = 1;
//}


GameState SnakeTextView ::getGameState() {
    if (isColliding()== true) return FINISHED_LOSS;
    else if (board1.board.size() - (2 * (board1.getBoardWidth() - 2) + 2 * (board1.getBoardHeight() - 2)) ==
             snake.size()) {
        return FINISHED_WIN;
    } else return RUNNING;
}

void SnakeTextView ::AppleGenerator() {
    int x, y;
    bool collision= true;
    do {
        x = rand() % (board1.getBoardWidth()-2)+1;
        y = rand() % (board1.getBoardHeight()-2)+1;
        for (int i = 1; i < snake.size(); i++) {
            int bodyX = snake[i] % board1.getBoardWidth();
            int bodyY = snake[i] / board1.getBoardWidth();
            if (bodyX == x && bodyY == y) {
                collision=true;
                break;
            } else collision=false;
        }
    } while (collision);

    board1.board[x + y * board1.getBoardWidth()] = 2;
}

void SnakeTextView::update() {
    moveStraight();

    if (isEating()== true) {
        score=score+1;
        growUp();
        AppleGenerator();
    }
    if (isColliding()== true) {
     //   board1.display();
        getGameState();
        if (mode==NORMAL) score=score;// /2;
        if (mode==HARD) score=score;// /3;
        cout << "GAME OVER, YOU'RE DEAD!\n";
        cout << "Your score: " << score << endl;
    }
//    else board1.display();
}
