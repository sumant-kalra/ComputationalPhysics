/*
 * Simulating the Monte Hall Problem
 * Problem statement:
 * Suppose you're on a game show,
 * and you're given the choice of three doors: Behind one door is a car;
 * behind the others, goats. You pick a door, say No. 1, and the host,
 * who knows what's behind the doors, opens another door, say No. 3, which has a goat.
 * He then says to you, "Do you want to pick door No. 2?"
 * Is it to your advantage to switch your choice?
 */

#include <iostream>
#include <cassert>
#include <random>
#include <chrono>
#include <cstdlib>

enum Door
{
    ONE = 1,
    TWO,
    THREE
};

static std::uniform_int_distribution<int> MH_Distribution(1, 3);
static auto MH_CurrentTime = std::chrono::high_resolution_clock::now().time_since_epoch();
static std::default_random_engine MH_Generator(MH_CurrentTime.count());

static bool hasWon(bool toSwitch)
{
    bool result = true;

    Door selectedDoor = Door(MH_Distribution(MH_Generator));
    Door correctDoor = Door(MH_Distribution(MH_Generator));

    if (!toSwitch)                            // The contestant choses not to switch
        result = selectedDoor == correctDoor; // Win only if he/she chose the correct door in the first time
    else                                      // The contestant choses to switch
        result = selectedDoor != correctDoor; // Wins only if he/she chose the incorrect door in the first time

    return result;
}

int main(int argc, char *argv[])
{
    assert(argc > 2 && "Missing arguments: <nRepetitions> <toSwitch(0:No,1:Yes)>\n");

    int64_t nRepetitions = atoll(argv[1]);
    bool switchDoor = atoi(argv[2]);

    int64_t nWins = 0;

    for (int64_t i = 0; i < nRepetitions; ++i)
        nWins += hasWon(switchDoor);

    std::cout << "Fraction of wins: " << double(nWins / double(nRepetitions)) << '\n';

    return 0;
}
