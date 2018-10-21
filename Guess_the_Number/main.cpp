#include <iostream>
#include <conio.h>
using namespace std;

int level = 1;
void Game();
void ChangeLevel();
void ShowMenu();

int main() 
{
	cout << "Welcome to our game - 'Guess the Number'!" << endl;
	ShowMenu();
}

void Game()
{
	int choosedNumber = rand() % 10 * level +1;
	bool result = false;
	int usersAnswer;
	cout << "I choosed the number. You should type number in range 1 to "<<level*10<<" ."<<endl;
	for (int numberTry = 1; numberTry <= 10; numberTry++)
	{
		if (numberTry == 10) cout << "You have last try.\n Good luck!" << endl;
		cout << "You  have " << numberTry << " tries to guess the number." << endl;
		cout << "Your answer: ";
		cin >> usersAnswer;
		if (usersAnswer == choosedNumber)
		{
			cout << "You win!" << endl;;
			result = true;
			break;
		}
		else if (usersAnswer < choosedNumber)
		{
			cout << "Greater!" << endl;
		}
		else if (usersAnswer > choosedNumber)
		{
			cout << "Less!" << endl;
		}
	}

	if (result == false) 
	{
		cout << "Sorry , but you lost T_T " << endl;
		cout << "Choosed number:" << choosedNumber << endl;
	}
	ShowMenu();
}

void ChangeLevel()
{
	cout << "Game has 10 levels difficulties. You should type the number in range 1 to 10." << endl;
	cout << "Your level:" << endl;
	cin >> level;
	if (level >= 1 && level < 4) cout << "So easy. Are you sure? *_*" << endl;
	else if (level < 7) cout << "Not bad , but i thought you are stronger #_#" << endl;
	else if (level < 10) cout << "Wow, good choice!" << endl;
	else if (level == 10) cout << "Oh, i see a suicide here!" << endl;
	cout << "Don't forget youu can change your level in menu!";
	ShowMenu();
}

void ShowMenu()
{
	int level = 1;
	char usersChoice;
	cout << "[Level " << level << "] Would you like to play? [p] - play, [l]- select level, [q] - quit" << endl;
	cout << "Your choice: ";
	cin >> usersChoice;
	do {
		switch (usersChoice)
		{
		case 'p': Game(); break;
		case 'l': ChangeLevel(); break;
		case 'q': cout << "Good bye! See you later!" << endl; exit(0); break;
		default: cout << "You should type one of these symbols :\n - p \n - l \n - q" << endl;
		}
	} while (true);
}