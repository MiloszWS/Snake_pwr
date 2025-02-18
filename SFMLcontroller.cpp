//
// Created by pmi03 on 04.05.2023.
//
#include "SFMLcontroller.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"
#include <synchapi.h>

SFMLcontroller :: SFMLcontroller(SnakeTextView& snake1, SFMLview & view1, otherWindows& screen1, scoreScreen & scoreSc1) :snake(snake1), view(view1), screen(screen1), scoreSc(scoreSc1){}

void SFMLcontroller ::play() {
    bool rageQuit= false;

    sf::RenderWindow Menuwindow(sf::VideoMode(900, 900), "Snake");
    Menuwindow.setVerticalSyncEnabled(false);
    Menuwindow.setFramerateLimit(60);
    bool choose= false;

    while (Menuwindow.isOpen()){
        Menuwindow.setKeyRepeatEnabled(false);
        sf::Event event;
        while (Menuwindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                rageQuit= true;
                Menuwindow.close();
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                // Sprawdzenie, czy przycisk Play został kliknięty na ekranie 1
                if (screen.isScreen1 && screen.buttonShape.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    if (choose == true){
                        Menuwindow.close(); // Zmiana ekranu na Game
                    }
                }

                if (screen.isScreen1 && screen.buttonEasy.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    screen.buttonEasy.setFillColor(sf::Color::Blue);
                    screen.buttonNormal.setFillColor(sf::Color(204, 0, 102));
                    screen.buttonHard.setFillColor(sf::Color(204, 0, 102));
                    snake.mode=EASY;
                    choose = true;
                }

                if (screen.isScreen1 && screen.buttonNormal.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    screen.buttonNormal.setFillColor(sf::Color::Blue);
                    screen.buttonEasy.setFillColor(sf::Color(204, 0, 102));
                    screen.buttonHard.setFillColor(sf::Color(204, 0, 102));
                    snake.mode=NORMAL;
                    choose = true;
                }

                if (screen.isScreen1 && screen.buttonHard.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    screen.buttonHard.setFillColor(sf::Color::Blue);
                    screen.buttonEasy.setFillColor(sf::Color(204, 0, 102));
                    screen.buttonNormal.setFillColor(sf::Color(204, 0, 102));
                    snake.mode=HARD;
                    choose = true;
                }
            }
        }

        Menuwindow.clear(sf::Color::Black);
        screen.drawMenuScreen(Menuwindow);
        Menuwindow.display();
    }
    if (rageQuit== false){
        sf::RenderWindow window(sf::VideoMode(900, 900), "Snake");
        window.setVerticalSyncEnabled(false);
        window.setFramerateLimit(200);

        EngineUtils::Timer* timer = EngineUtils::Timer::Instance();

        while (window.isOpen())
        {
            window.setKeyRepeatEnabled(false);

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    rageQuit= true;
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Down){
                        snake.goDOWN();
                    } else if (event.key.code == sf::Keyboard::Up){
                        snake.goUP();
                    } else if (event.key.code == sf::Keyboard::Right){
                        snake.turnRight();
                    } else if (event.key.code == sf::Keyboard::Left){
                        snake.turnLeft();
                    }
                }
            }

            if (snake.getGameState()==RUNNING){
                timer->Tick();
                if (timer->DeltaTime() >= 5 / 60.0f) {
                    timer->Reset();
                    snake.update();
                }

            }
            if (view.isScreen1 && view.buttonShape.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                if (choose == true){
                    window.close(); // Zmiana ekranu na Game
                }
            }


            window.clear(sf::Color::Cyan);
            view.draw(window);
            window.display();

        }
        EngineUtils::Timer::Release();
    }

    if (rageQuit== false) {
        sf::RenderWindow NicknameWindow(sf::VideoMode(900, 900), "Snake");
        NicknameWindow.setVerticalSyncEnabled(false);
        NicknameWindow.setFramerateLimit(100);

        std::string nickname;


        while (NicknameWindow.isOpen()) {
            while (NicknameWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    rageQuit = true;
                    NicknameWindow.close();
                } else if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == 13) { // Enter key
                        NicknameWindow.close();
                    } else if (event.text.unicode == 8 && !nickname.empty()) { // Backspace key
                        nickname.pop_back();
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) { // Printable characters
                        if (event.text.unicode != 32) { // Skip space character
                            nickname += static_cast<char>(event.text.unicode);
                        }
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) { // Printable characters
                        nickname += static_cast<char>(event.text.unicode);
                    }
                }
            }

            scoreSc.inputText.setString(nickname);

            scoreSc.lastNickname = nickname;

            NicknameWindow.clear(sf::Color::Cyan);
            scoreSc.inputNickname(NicknameWindow);
            NicknameWindow.display();
        }
    }
    if (rageQuit== false) {
        sf::RenderWindow ScoreWindow(sf::VideoMode(900, 900), "Snake");
        ScoreWindow.setVerticalSyncEnabled(false);
        ScoreWindow.setFramerateLimit(100);


        while (ScoreWindow.isOpen()) {

            while (ScoreWindow.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    rageQuit = true;
                    ScoreWindow.close();
                }
                if (scoreSc.quitButton.getGlobalBounds().contains(
                        sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    ScoreWindow.close();
                }
                if (scoreSc.menuButton.getGlobalBounds().contains(
                        sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    BoardTextView board(20, 20);
                    SnakeTextView view1(board);
                    SFMLview view(view1, board);
                    otherWindows view2(view1, board);
                    scoreScreen view3(board, view1);
                    SFMLcontroller ctrl(view1, view, view2, view3);
                    ScoreWindow.close();
                    ctrl.play();
                }
            }

            ScoreWindow.clear(sf::Color::Black);
            scoreSc.drawScoreScreen(ScoreWindow);
            scoreSc.dataStuff(ScoreWindow);
            ScoreWindow.display();

        }
    }
}