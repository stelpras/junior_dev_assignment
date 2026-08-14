#include "Tennis.h"
#include <cstdlib>

using namespace std;

// kept private to this file - nothing outside needs to know about these.
namespace {

const string SCORE_NAMES[4] = { "Love", "Fifteen", "Thirty", "Forty" };

// turns raw point counts into the tennis score string.
string formatScore(int p1Points, int p2Points, const string& name1, const string& name2) {
    if (p1Points == p2Points) {
        if (p1Points < 3) {
            return SCORE_NAMES[p1Points] + "-All";
        }
        return "Deuce";
    }

    // at least one player is past 40.
    if (p1Points >= 4 || p2Points >= 4) {
        int difference = p1Points - p2Points;

        // 2+ points ahead wins. Exactly 1 point ahead is advantage.
        if (difference >= 2) {
            return "Win for " + name1;
        }
        if (difference <= -2) {
            return "Win for " + name2;
        }
        if (difference == 1) {
            return "Advantage " + name1;
        }
        return "Advantage " + name2;  // only case left: difference == -1
    }

    //both players under 40.
    return SCORE_NAMES[p1Points] + "-" + SCORE_NAMES[p2Points];
}

}


Player::Player(const string& name) : name(name) {}

const string& Player::getName() const {
    return name;
}

Umpire::Umpire(string player1Name, string player2Name)
    : player1(player1Name), player2(player2Name) {}

// adds a point to whichever player matches the name. 
void Umpire::rememberScore(const string& playerName) {
    if (playerName == player1.getName()) {
        player1Points++;
    } else if (playerName == player2.getName()) {
        player2Points++;
    }
}

// records the point (unless the game is already over) and returns the score.
string Umpire::announcePoint(const string& playerName) {
    if (!endGame()) {
        rememberScore(playerName);
    }
    return score();
}

// current score, read-only - doesn't award any point.
string Umpire::score() const {
    return formatScore(player1Points, player2Points, player1.getName(), player2.getName());
}

// true once someone has won: reached 40+ and leads by 2 or more points.
bool Umpire::endGame() const {
    bool eitherPastForty = player1Points >= 4 || player2Points >= 4;
    bool twoPointLead = abs(player1Points - player2Points) >= 2;
    return eitherPastForty && twoPointLead;
}