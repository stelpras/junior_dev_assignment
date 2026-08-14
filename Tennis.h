#pragma once

#include <string>

using namespace std;

class Player {
public:
    Player(const string& name);
    const string& getName() const;

private:
    string name;
};

class Umpire {
public:
    Umpire(string player1Name, string player2Name);

    // gives a point to playerName and returns the new score.
    string announcePoint(const string& playerName);

    bool endGame() const;

    string score() const;

private:
    void rememberScore(const string& playerName);

    Player player1;
    Player player2;
    int player1Points = 0;
    int player2Points = 0;
};