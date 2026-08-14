#include "Tennis.h"
#include <iostream>
#include <string>

using namespace std;

namespace {

int failures = 0;

void check(const string& actual, const string& expected, const string& testName) {
    if (actual != expected) {
        cout << "FAIL " << testName << ": expected \"" << expected
             << "\" but got \"" << actual << "\"\n";
        ++failures;
    } else {
        cout << "OK   " << testName << " -> \"" << actual << "\"\n";
    }
}

// Interleaves points so intermediate states never falsely trip endGame().
string finalScoreAfter(int p1, int p2) {
    Umpire umpire("Player1", "Player2");
    int remaining1 = p1;
    int remaining2 = p2;
    string lastAnnounced = umpire.score();
    while (remaining1 > 0 || remaining2 > 0) {
        if (remaining1 > 0) { lastAnnounced = umpire.announcePoint("Player1"); remaining1--; }
        if (remaining2 > 0) { lastAnnounced = umpire.announcePoint("Player2"); remaining2--; }
    }
    return lastAnnounced;
}

} // namespace

int main() {
    // score() works before any point is announced.
    {
        Umpire umpire("Player1", "Player2");
        check(umpire.score(), "Love-All", "initial_score_before_any_point");
    }

    // All combinations from 0-0 up to 3-3 (Love through Forty on both sides).
    check(finalScoreAfter(0, 0), "Love-All", "love_all");
    check(finalScoreAfter(0, 1), "Love-Fifteen", "love_fifteen");
    check(finalScoreAfter(0, 2), "Love-Thirty", "love_thirty");
    check(finalScoreAfter(0, 3), "Love-Forty", "love_forty");
    check(finalScoreAfter(1, 0), "Fifteen-Love", "fifteen_love");
    check(finalScoreAfter(1, 1), "Fifteen-All", "fifteen_all");
    check(finalScoreAfter(1, 2), "Fifteen-Thirty", "fifteen_thirty");
    check(finalScoreAfter(1, 3), "Fifteen-Forty", "fifteen_forty");
    check(finalScoreAfter(2, 0), "Thirty-Love", "thirty_love");
    check(finalScoreAfter(2, 1), "Thirty-Fifteen", "thirty_fifteen");
    check(finalScoreAfter(2, 2), "Thirty-All", "thirty_all");
    check(finalScoreAfter(2, 3), "Thirty-Forty", "thirty_forty");
    check(finalScoreAfter(3, 0), "Forty-Love", "forty_love");
    check(finalScoreAfter(3, 1), "Forty-Fifteen", "forty_fifteen");
    check(finalScoreAfter(3, 2), "Forty-Thirty", "forty_thirty");
    check(finalScoreAfter(3, 3), "Deuce", "deuce");

    // Beyond 40: advantage and win, both directions.
    check(finalScoreAfter(4, 3), "Advantage Player1", "advantage_player1");
    check(finalScoreAfter(3, 4), "Advantage Player2", "advantage_player2");
    check(finalScoreAfter(5, 3), "Win for Player1", "win_player1");
    check(finalScoreAfter(3, 5), "Win for Player2", "win_player2");

    // endGame() correctly flags a decided game.
    {
        Umpire umpire("Player1", "Player2");
        umpire.announcePoint("Player1");
        check(umpire.endGame() ? "true" : "false", "false", "not_finished_yet");
    }

    cout << "\n" << (failures == 0 ? "ALL TESTS PASSED" : to_string(failures) + " TEST(S) FAILED") << "\n";
    return failures == 0 ? 0 : 1;
}