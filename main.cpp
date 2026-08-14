#include "Tennis.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

int main() {
    mt19937 rng(random_device{}());
    bernoulli_distribution coinFlip(0.5);

    Umpire umpire("Player1", "Player2");

    cout << "Simulating a tennis game, live.\n\n";
    cout << "Starting score: " << umpire.score() << "\n\n";

    int step = 0;

    while (!umpire.endGame()) {
        string winner = coinFlip(rng) ? "Player1" : "Player2";
        string newScore = umpire.announcePoint(winner);
        ++step;

        cout << "Step " << step << ": " << winner << " wins the point.\n";
        cout << "    Score: " << newScore << "\n\n";

        this_thread::sleep_for(600ms);
    }

    cout << "=========================\n";
    cout << "GAME OVER - " << umpire.score() << "\n";
    cout << "=========================\n";

    return 0;
}