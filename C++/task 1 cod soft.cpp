#include <iostream>
#include <ctime>
#include <cstdlib>

class NumberGuessingGame {
public:
    NumberGuessingGame() {
        secret = rand() % 100 + 1;
    }

    void play() {
        int guess;
        int attempts = 10;

        std::cout << "Welcome to the Number Guessing Game!" << std::endl;
        std::cout << "I have randomly chosen a number between 1 and 100." << std::endl;
        std::cout << "You have 10 attempts to guess the number." << std::endl;

        for (int i = 0; i < attempts; ++i) {
            std::cout << "Enter your guess (" << (attempts - i) << " attempts left): ";
            std::cin >> guess;

            if (guess < secret) {
                std::cout << "Too low! Try again." << std::endl;
            } else if (guess > secret) {
                std::cout << "Too high! Try again." << std::endl;
            } else {
                std::cout << "Congratulations! You guessed the number in " << (i + 1) << " attempts." << std::endl;
                return;
            }
        }

        std::cout << "Sorry, you didn't guess the number. The correct answer was " << secret << "." << std::endl;
    }

private:
    int secret;
};

int main() {
    srand(time(0));

    NumberGuessingGame game;
    game.play();

    return 0;
}
