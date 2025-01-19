#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have generated a random number between 1 and 100. Try to guess it!\n";

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Provide feedback
        if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number correctly.\n";
        }
    }

    return 0;
}

