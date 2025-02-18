//
// Created by pmi03 on 07.05.2023.
//
#include <valarray>
#include "scoreScreen.h"
#include <fstream>
#include <sstream>

using namespace std;

scoreScreen ::scoreScreen(BoardTextView &board1, SnakeTextView &snake1) :board(board1), snake(snake1){
    font= sf::Font();
    font.loadFromFile("../Textures/WockeFunky.ttf");


    numbers.setFont(font);
    numbers.setCharacterSize(40);
    numbers.setPosition(250, 130);
    numbers.setOutlineThickness(5);
    numbers.setOutlineColor(sf::Color::Black);
    numbers.setFillColor(sf::Color(0, 139, 139));

    playersScores.setFont(font);
    playersScores.setCharacterSize(40);
    playersScores.setPosition(25, 130);
    playersScores.setOutlineThickness(5);
    playersScores.setOutlineColor(sf::Color::Black);
    playersScores.setFillColor(sf::Color(255,255, 255));

    nickNumbers.setFont(font);
    nickNumbers.setCharacterSize(40);
    nickNumbers.setPosition(130, 130);
    nickNumbers.setOutlineThickness(5);
    nickNumbers.setOutlineColor(sf::Color::Black);
    nickNumbers.setFillColor(sf::Color(0, 139, 139));

    scoreText.setFont(font);
    scoreText.setString("SCOREBOARD");
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(sf::Color(0, 139, 139));
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(5);
    scoreText.setPosition(210, 5);

    autorText1.setFont(font);
    autorText1.setString("Writed by:");
    autorText1.setCharacterSize(40);
    autorText1.setFillColor(sf::Color(0, 139, 139));
    autorText1.setOutlineColor(sf::Color::Black);
    autorText1.setOutlineThickness(5);
    autorText1.setPosition(500, 500);

    autorText2.setFont(font);
    autorText2.setString("Milosz  273116");
    autorText2.setCharacterSize(40);
    autorText2.setFillColor(sf::Color(0, 139, 139));
    autorText2.setOutlineColor(sf::Color::Black);
    autorText2.setOutlineThickness(5);
    autorText2.setPosition(550, 600);

    scoreText.setFont(font);
    scoreText.setString("SCOREBOARD");
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(sf::Color(0, 139, 139));
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(5);
    scoreText.setPosition(210, 5);

    promptText.setFont(font);
    promptText.setCharacterSize(60);
    promptText.setFillColor(sf::Color::Red);
    promptText.setPosition(50, 100);
    promptText.setString("PLEASE WRITE YOUR NICKNAME: ");
    promptText.setOutlineColor(sf::Color::Black);
    promptText.setOutlineThickness(5);

    inputText.setFont(font);
    inputText.setCharacterSize(50);
    inputText.setFillColor(sf::Color::Red);
    inputText.setPosition(350, 250);
    inputText.setOutlineColor(sf::Color::Black);
    inputText.setOutlineThickness(5);

    menuButton.setPosition(500, 350);
    menuButton.setSize(sf::Vector2f(250, 50));
    menuButton.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    menuButton.setOutlineColor(sf::Color::Black);
    menuButton.setOutlineThickness(5);
    // Ustawienie tekstu na przycisku
    buttonText.setFont(font);
    buttonText.setString("Return to Menu");
    buttonText.setCharacterSize(30); // Możesz dostosować rozmiar czcionki
    buttonText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki
    // Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    buttonText.setPosition(500 + 250 / 2, 350 + 50 / 2);
    buttonText.setOutlineColor(sf::Color::Black);
    buttonText.setOutlineThickness(5);

    quitButton.setPosition(780, 840);
    quitButton.setSize(sf::Vector2f(100, 40));
    quitButton.setFillColor(sf::Color(204, 0, 102)); // Możesz dostosować kolor
    quitButton.setOutlineColor(sf::Color::Black);
    quitButton.setOutlineThickness(5);
    // Ustawienie tekstu na przycisku
    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(30); // Możesz dostosować rozmiar czcionki
    quitText.setFillColor(sf::Color::Green); // Możesz dostosować kolor czcionki
    // Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect quitTextBounds = quitText.getLocalBounds();
    quitText.setOrigin(quitTextBounds.left + quitTextBounds.width / 2, quitTextBounds.top + quitTextBounds.height / 2);
    quitText.setPosition(780 + 100 / 2, 840 + 40 / 2);
    quitText.setOutlineColor(sf::Color::Black);
    quitText.setOutlineThickness(5);

}

void scoreScreen ::drawScoreScreen(sf:: RenderWindow & window) {

//    float radius = 200.0f;
//    float centerX = 400.0f;
//    float centerY = 300.0f;
//    float angle = 0.0f;
//    float angularStep = 0.1f;
//    float x = centerX + radius * std::cos(angle);
//    float y = centerY + radius * std::sin(angle);



    sf :: Texture icon;
    icon.loadFromFile("../Textures/ScoreWall.png");
    sf::Sprite sprite;
    sprite.setTexture(icon);
    sprite.setScale(0.155f, 0.155f);

    int repeatX = window.getSize().x / 38;
    int repeatY = window.getSize().y / 38;

    for (int y = 0; y < repeatY; ++y)
    {
        for (int x = 0; x < repeatX; ++x)
        {
            // Oblicz pozycję sprite'a na ekranie
            float posX = x*40;
            float posY = y*40;

            sprite.setPosition(posX, posY);
            window.draw(sprite);

        }
    }

    string numberList;
    for (int i = 1; i <= 10; i++) {
        numberList += std::to_string(i) + ".\n\n";
    }
    numbers.setString(numberList);


    window.draw(numbers);
    window.draw(scoreText);
    window.draw(menuButton);
    window.draw(buttonText);
    window.draw(quitButton);
    window.draw(quitText);
    window.draw(autorText1);
    window.draw(autorText2);

}

void scoreScreen ::dataStuff(sf:: RenderWindow & window) {

    std::vector<int> scores;
    std::ifstream file("D://CLion//Projects//Snake//Score.txt");  // Otwarcie pliku do odczytu

    if (!file) {
        std::cout << "Błąd podczas otwierania pliku." << std::endl;
    }

    int score;
    while (file >> score) {
        scores.push_back(score);
    }
    scores.push_back(snake.score);

    int helper;
    while (!file.eof()){
        while (file>>helper){
            scores.push_back(helper);
        }
    }
    file.close();

    sort(scores.begin(), scores.end(), greater<int>());

    for (int i = 0; i < 10; ++i) {
        std::string scoreStr = std::to_string(scores[i]);
        playersScores.setString(scoreStr);
        sf::FloatRect textRect = playersScores.getLocalBounds();
        playersScores.setOrigin(textRect.left + textRect.width, textRect.top);
        playersScores.setPosition( 390, 130+i*75);

        window.draw(playersScores);
    }
//        std::vector<Player> players;  // Kontener przechowujący graczy
//
//        std::string line;
//        while (std::getline(file, line)) {  // Odczyt linii z pliku
//            std::istringstream iss(line);
//            std::string Nick;
//            int Score;
//
//            if (iss >> Nick >> Score) {  // Podział linii na imię i wynik
//                Player player;
//                player.Nick = Nick;
//                player.Score = Score;
//
//                players.push_back(player);  // Dodanie gracza do kontenera
//            } else {
//                std::cout << "Błąd odczytu linii: " << line << std::endl;
//            }
//        }
//
//        file.close();  // Zamknięcie pliku
//
//        int lastScore=snake.score;
//
//    bool placed = false;
//    for (int i = 0; i < players.size(); ++i) {
//        if (lastScore > players[i].Score) {
//            Player newPlayer;
//            newPlayer.Nick = lastNickname;
//            newPlayer.Score = lastScore;
//            sort(players, i);
//            players[i] = newPlayer;
//            placed = true;
//            break;
//        }
//    }
//
//    if (!placed) {
//        Player newPlayer;
//        newPlayer.Nick = lastNickname;
//        newPlayer.Score = lastScore;
//        players.insert(players.begin(), newPlayer);
//    }
//
//
//
//        // Przykład dostępu do danych graczy
//
//            string firstPlayerNick = players[0].Nick;
//            string secondPlayerNick = players[1].Nick;
//            string thirdPlayerNick = players[2].Nick;
//            string forthPlayerNick = players[3].Nick;
//            string fifthPlayerNick = players[4].Nick;
//            string sixthPlayerNick = players[5].Nick;
//            string seventhPlayerNick = players[6].Nick;
//            string eightPlayerNick = players[7].Nick;
//            string ninthPlayerNick = players[8].Nick;
//            string tenthPlayerNick = players[9].Nick;
//
//            int firstPlayerScore = players[0].Score;
//            int secondPlayerScore = players[1].Score;
//            int thirdPlayerScore = players[2].Score;
//            int forthPlayerScore = players[3].Score;
//            int fifthPlayerScore = players[4].Score;
//            int sixthPlayerScore = players[5].Score;
//            int seventhPlayerScore = players[6].Score;
//            int eightPlayerScore = players[7].Score;
//            int ninthPlayerScore = players[8].Score;
//            int tenthPlayerScore = players[9].Score;
//
//
//
//    for (int i = 0; i < 9; ++i) {
//        std::string scoreStr = std::to_string(players[i].Score);
//        playersScores.setString(scoreStr);
//        sf::FloatRect textRect = playersScores.getLocalBounds();
//        playersScores.setOrigin(textRect.left + textRect.width, textRect.top);
//        playersScores.setPosition( 340, 130+i*60);
//
//        window.draw(playersScores);
//    }
//
}

void scoreScreen ::inputNickname(sf::RenderWindow &window) {

    window.draw(promptText);
    window.draw(inputText);
}

//void scoreScreen ::sort(std::vector<Player> &players, int index) {
//    for (int i = players.size() - 1; i >= index; --i) {
//        players[i] = players[i - 1];
//    }
//}