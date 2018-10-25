#include  "iostream"
#include "conio.h"
#include "ctime"
#include "array"
using namespace std;
// size map
const int mapColumns = 15;
const int mapRows = 15;

using Map = array<array<char, mapColumns>, mapRows>;

const char mapCodeUser = '@';
// location Exit in the maze
int locationExitRow; 
int locationExitColumn;
// location User in th maze
int locationUserRow;
int locationUserColumn;
//symbols for maze
const char mapCodeExit = 'E';
const char mapCodeWall = '#';
const char mapCodeField = ' ';
//check if user wants to play
bool doesUserWantToPlay()
{
	bool result = false;
	char answer = '\0';
	do
	{
		cout << "Maze Game" << endl;
		cout << "Do you want to play a game?(1-Yes| 0-No)" << endl;
		cin >> answer;
		if (answer == '1')
		{
			result = true;
			break;
		}

		else if (answer == '0')
		{
			result = false;
			break;
		}
		cout << "I dont understand you!" << endl;

	} while (true);
	return result;
}
// check if location is dead end
bool isDeadEnd(int row, int column, Map &map) 
{
	if ((map[row][column + 2] != mapCodeField) && ((column + 2) < (mapColumns - 1)))
		{
			return false;
		
		}
	if ((map[row+2][column] != mapCodeField) && ((row + 2) < (mapRows - 1)))
		 {
			 return false;

		}
	if ((map[row][column - 2] != mapCodeField) || ((column - 2) >0))
		{
			return false;
		}
	if ((map[row-2][column] != mapCodeField) || ((row - 2) >0))
		{
			return false;
		}

	return true;

}
// show maze on the display
void display(const Map &map)
{
	for (int column = 0; column < mapColumns; ++column)
	{
		for (int row = 0; row < mapRows; ++row)
		{
			cout << map[row][column];
		}
		cout << endl;
	}
}
// generate maze for the game
void fill(Map &map)
{
	for (int column = 0; column < mapColumns; ++column)
	{
		for (int row = 0; row < mapRows; ++row)
		{
			map[row][column] = mapCodeWall;
		}
	}
	locationUserColumn = rand() % (mapColumns - 3) + 2;
	locationUserRow = rand() % (mapRows - 3) + 2;
	int numberIteration = 0;
	int locationColumn= locationUserColumn;
	int locationRow = locationUserRow; 
	int tempRow ,tempColumn;
	int directionRow , directionColumn;
	int direction=0;
	do {
			directionColumn = 0;
			directionRow = 0;
			direction = rand() % 4 + 1;
			switch (direction) {
			case 1: directionRow = -1; break;
			case 2: directionColumn = -1; break;
			case 3: directionRow = 1; break;
			case 4: directionColumn = 1; break;
			}
		
			tempColumn = locationColumn + 2 * directionColumn;
			tempRow= locationRow + 2 * directionRow;
			direction = 0;
			if ((tempColumn >0) && (tempRow > 0) && (map[tempRow][tempColumn] == mapCodeWall)
				&& (tempRow < (mapColumns-1)) && ( tempColumn < (mapRows-1)))
			{
				map[tempRow - directionRow][tempColumn - directionColumn] = mapCodeField;
				map[tempRow ][tempColumn] = mapCodeField;
				locationRow = tempRow;
				locationColumn = tempColumn;
											
			}
			
			if (isDeadEnd(locationRow, locationColumn, map))
			{
				do 
				{
					locationColumn= rand() % (mapColumns - 3) + 2;
					locationRow = rand() % (mapRows - 3) + 2;
				} while (map[locationRow][locationColumn] == mapCodeField);
			}
		map[locationRow][locationColumn] = mapCodeField;
		numberIteration++;
	} while (numberIteration < 1000);
	locationExitRow=locationRow;
	locationExitColumn = locationColumn;
	map[locationUserRow][locationUserColumn] = mapCodeUser;
	map[locationExitRow][locationExitColumn] = mapCodeExit;
}
// user's movement in the maze
bool UsersMove(Map&map, char direction)
{
	bool result = false;
	int tempLocationUserColumn = locationUserColumn;
	int tempLocationUserRow = locationUserRow;
	cout << locationUserRow << endl;
	cout << locationUserColumn << endl;

	switch (direction)
	{
	case 'w': tempLocationUserColumn--; break;
	case 's': tempLocationUserColumn++; break;
	case 'a': tempLocationUserRow--; break;
	case 'd': tempLocationUserRow++; break;
	}
	if (map[tempLocationUserRow][tempLocationUserColumn] != mapCodeWall)
	{
		map[locationUserRow][locationUserColumn] = mapCodeField;
		locationUserColumn = tempLocationUserColumn;
		locationUserRow = tempLocationUserRow;
		if (map[locationUserRow][locationUserColumn] == mapCodeExit)
		{
			cout << "You found exit! Good job!" << endl;
			result = true;

		}
		map[locationUserRow][locationUserColumn] = mapCodeUser;
	}
	else
	{
		cout << "There is wall." << endl;
	}
	return result;

}
//main function for the game
void Game(Map &map) {
	fill(map);
	char usersAction;
	do {
		display(map);
		cout << "For move use : [a]-left , [d]-right, [w]-up, [s]-down." << endl;
		cout << "If you want to stop you should type [q]." << endl;
		cout << "If you want to restart you should type [r]." << endl;
		cout << "Your action:";
		cin >> usersAction;
		if (usersAction == 'q')
		{
			cout << "Good bye!" << endl;
			exit(0);
		}
		if (usersAction == 'r')
		{
			Game(map);
		}
		if (UsersMove(map, usersAction))
		{
			break;
		}

	} while (true);
}
// start the game
void startGame()
{
	cout << "Playing" << endl;
	Map map;
	Game(map);
}
int main() {
	while (doesUserWantToPlay()) 
	{
		startGame();
	}

	_getch();
	return 0;
}