#include <iostream>
#include <time.h>

// Three rules for the C++ class:
// 1. No global variables. (Global constants are all right.)
// 2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
// 3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".

using namespace std;

int main()
{

	char playAgain;
	do
	{
		int numberOfGuesses = 0; // variable to keep track of the number of guesses
		srand(time(NULL)); // set the random number
		int randomNumber = rand() % 101; // generate random number between 0 and 100
		int playerGuess = -1; // initialize player's guess with an invalid number
		cout << "Guess a number between 0 and 100!" << endl;

		while (playerGuess != randomNumber) // loop until the player guesses the correct number
		{
			cout << "Enter your guess: " << endl;
			cin >> playerGuess; // read the player's guess

			numberOfGuesses++; // increase the number of guesses by 1

			if(playerGuess > randomNumber)
				cout << "Too high! Try again." << endl;

			else if (playerGuess < randomNumber)
				cout << "Too low! Try again." << endl;

			else
				cout << "You guessed the number in " << numberOfGuesses << " tries." << endl;

		}

		cout << "Play again (y/n)?" << endl; // ask the player if they want to play again
		cin >> playAgain;

	} while(playAgain == 'y' || playAgain == 'Y'); //restart the game if the player chooses 'y' or 'Y'

	return 0;
}


