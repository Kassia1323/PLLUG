#include <iostream>
#include <conio.h>
#include <string>
#include <array>
using namespace std;
const int array_size = 3;
array<string, array_size> versions = { "Rock","Scissors","Paper" };

int usersAnswer() 
{
	string usersChoice;
	int indexUsersChoice;
	do {
		cout << "You should type one of these words :\n - Rock\n - Scissor\n - Paper" << endl;
		cout << "Your answer:" << endl;
		cin >>usersChoice;
		if (usersChoice == "Rock" || usersChoice == "rock")
		{
			indexUsersChoice = 0;
			return indexUsersChoice;
		}
		else if (usersChoice == "Scissors" || usersChoice == "scissors")
		{
			indexUsersChoice = 1;
			return indexUsersChoice;
		}
		else if (usersChoice == "Paper" || usersChoice == "paper")
		{
			indexUsersChoice = 2;
			return indexUsersChoice;
		}

	} while (true);
}
int programsAnswer() 
{
	return rand() % 3;
}
void Game() {
	int uAnswer = usersAnswer();
	int pAnswer = programsAnswer();
	string oneMore = "\0";
	cout << "Your answer:" << versions[uAnswer] << endl;
	cout << "Program's answer:" << versions[pAnswer] << endl;
	if (uAnswer == pAnswer)
	{
		cout << "Draw!"<<endl;
	}
	else if ((uAnswer == 0 && pAnswer==1)
			||(uAnswer == 1 && pAnswer == 2)
			||(uAnswer == 2 && pAnswer == 0))
		{
		 cout << "Win!" << endl;;
		}
	else
		{	
			cout << "Lose!"<<endl;
		}
	
	do {
		cout << "Do u want to play one more?(1-Yes|2-No)" << endl;
		cin >> oneMore;
		if (oneMore == "1") {
			Game();
		}
		if (oneMore == "2") {
			cout << "Goodbye, see you later!" << endl;
			exit(0);
		}
		cout << "You have to write 1 or 2." << endl;
	} while (true);
		
}

int main()
{
	cout << "Lets play Rock, Scissors, Paper!" << endl;
	Game();
	_getch();
	return 0;
}
