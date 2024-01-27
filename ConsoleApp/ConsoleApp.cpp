#include <iostream>
#include <cstdlib>  
#include <ctime> 

using namespace std;

enum Choice
{
	ROCK=1, //comment
	PAPER,
	SCISSORS
};

enum number
{
    NUM1,
    NUM2,
    NUM3,
    NUM4
};

enum light
{
    RED,
    YELLOW,
    GREEN
};

//Hello World 
class Manager
{
    Manager()
    {
        cout << "Manager class created" << endl;
    }
};

class Player {
public:
	virtual Choice makeChoice() = 0;  // Pure virtual function for making a choice
	virtual ~Player() {}  // Virtual destructor for polymorphism
};

class HumanPlayer : public Player {
public:
	Choice makeChoice() override {
		int choice;
		std::cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
		std::cin >> choice;

		// Validate the input
		if (choice < 0 || choice > 2) {
			std::cout << "Invalid choice. Defaulting to Rock.\n";
			return ROCK;
		}

		return static_cast<Choice>(choice);
	}
};

class Chess
{
    
};

class ComputerPlayer : public Player {
public:
	Choice makeChoice() override {
		return static_cast<Choice>(rand() % 3);  // Randomly choose Rock, Paper, or Scissors
	}
};

void determineWinner(Choice playerChoice, Choice computerChoice) {
    std::cout << "Player chose ";
    switch (playerChoice) {
    case ROCK: std::cout << "Rock"; break;
    case PAPER: std::cout << "Paper"; break;
    case SCISSORS: std::cout << "Scissors"; break;
    }

    std::cout << "\nComputer chose ";
    switch (computerChoice) {
    case ROCK: std::cout << "Rock"; break;
    case PAPER: std::cout << "Paper"; break;
    case SCISSORS: std::cout << "Scissors"; break;
    }

    // Determine the winner
    if (playerChoice == computerChoice) {
        std::cout << "\nIt's a tie!\n";
    }
    else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
        (playerChoice == PAPER && computerChoice == ROCK) ||
        (playerChoice == SCISSORS && computerChoice == PAPER)) {
        std::cout << "\nPlayer wins!\n";
    }
    else {
        std::cout << "\nComputer wins!\n";
    }
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create player objects
    HumanPlayer humanPlayer;
    ComputerPlayer computerPlayer;

    // Get choices from players
    Choice playerChoice = humanPlayer.makeChoice();
    Choice computerChoice = computerPlayer.makeChoice();

    // Determine the winner
    determineWinner(playerChoice, computerChoice);

    return 0;
}
