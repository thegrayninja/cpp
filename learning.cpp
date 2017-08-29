//simply storing this incomplete code for future reference

#include <iostream>
#include <string>	// to be used for cin into type string

using namespace std;


void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();



int main()
{

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0; // exit the application
}



void PrintIntro()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;

	return;
}


void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0; count < NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "You typed: " << Guess << endl;
		cout << endl;
	}

	return;
}


string GetGuess()
{
	// get a guess from the player
	string Guess = "";
	cout << "Please type a word: ";
	getline(cin, Guess);

	return Guess;
}


bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n): ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');


}
