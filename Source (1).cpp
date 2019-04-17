#include <iostream>
#include <string>
using namespace std;
struct player
{
	string name;
	char ch;
}p1,p2;
#define width 8
#define height 8
int arr[width][height] = { 0 };
int numrow,numcol;
void choice();
void drawboard();
void input(int, int);
bool check_all(int);
bool end_game(int);
void main()
{
	choice();
	drawboard();
	int count = 0;
	while (true)
	{
		for (int i = 0; i < width*height; i++)
		{
			cout << p1.name << ":  ";
			cin >> numcol;
			count++;
			input(count, numcol);
			if (check_all(numcol) == 1)
			{
				system("cls");
				cout << p1.name << " WON!" << endl;
				if (end_game(count) == 0)
				{
					break;
				}
				else{
					i = 0;
				}
			}
			cout << p2.name << ":   ";
			cin >> numcol;
			count++;
			input(count, numcol);
			if (check_all(numcol) == 1)
			{
				system("cls");
				cout << p2.name << " WON!" << endl;
				if (end_game(count) == 0)
				{
					break;
				}
				else{
					i = 0;
				}
			}
		}
		if (check_all(numcol) == 0)
		{
			cout << "NONE OF YOU WON!" << endl;
			if (end_game(count) == 0)
			{
				break;
			}
		}
		else{
			break;
		}
	}
	
	system("PAUSE");
}
void drawboard()
{
	cout << "                     CONNECT FOUR GAME" << endl;
	cout << endl ;
	for (int i = 1; i <= height; i++)
	{
		cout <<"    " <<i<<"   " ;
	}
	cout << endl;
	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j<height; j++)
		{
			cout << "|";
			if (arr[i][j] == 0)
			{
				cout << "       ";
			}
			else if (arr[i][j] == 1)
			{
				cout << "   " << p1.ch << "   ";
			}
			else if (arr[i][j] == 2)
			{
				cout << "   " << p2.ch << "   ";
			}
		}
		cout << "|" << endl<<'-';
		for (int i = 1; i <= height; i++)
		{
			cout << "--------";
		}
		cout << endl;
	}

}
void choice()
{
	cout << "Enter Player 1 Name : ";
	cin >> p1.name;
	cout << "Enter Player 2 Name : ";
	cin >> p2.name;
	system("cls");
	cout << "Enter Player 1 character : ";
	cin >> p1.ch;
	cout << "Enter Player 2 character : ";
	cin >> p2.ch;
	while (p1.ch == p2.ch)
	{
		cout << "Choose another character : ";
		cin >> p2.ch;
	}
	system("cls");
}
void input(int count, int numcol)
{
	numrow = width-1;
	while (numcol >height || numcol <= 0)
	{
		cout << "TRY AGAIN" << endl;
		cin >> numcol;
	}
	while (arr[numrow][numcol - 1] != 0)
	{
		numrow--;
		if (arr[0][numcol - 1] != 0)
		{
			cout << "ERROR!" << endl << "TRY AGAIN" << endl;
			cin >> numcol;
		}
	}
	if (count % 2 != 0)
	{
		arr[numrow][numcol - 1] = 1;

	}
	else {
		arr[numrow][numcol - 1] = 2;
	}
	system("cls");
	drawboard();
}
bool check_row(int numcol)
{
	int score = 0;
	bool win = 0;
	for (int i = numcol - 1; i < height; i++)
	{
		if (arr[numrow][i] == arr[numrow][i + 1])
		{
			score++;
		}
		else{
			break;
		}
	}

	for (int i = numcol - 1; i >= 0; i--)
	{
		if (arr[numrow][i] == arr[numrow][i - 1])
		{
			score++;
		}
		else{
			break;
		}
	}
	if (score >= 3)
	{
		win = 1;
	}
	return win;
}
bool check_col(int numcol)
{
	bool win = 0;
	int score = 0;
	for (int i = numrow + 1; i < width; i++)
	{
		if (arr[numrow][numcol - 1] == arr[i][numcol - 1])
		{
			score++;
		}
		else{
			break;
		}
	}
	if (score == 3)
	{
		win = 1;
	}
	return win;
}
bool check_diagonal(int numcol)
{
	bool win = 0;
	int score = 0, score1 = 0;

	for (int i = numcol, j = numrow - 1; i < height, j >= 0; i++, j--)
	{
		if (arr[numrow][numcol - 1] == arr[j][i])
		{
			score++;
		}
		else{
			break;
		}

	}
	for (int i = numcol - 2, j = numrow + 1; i >= 0, j < width; i--, j++)
	{
		if (arr[numrow][numcol - 1] == arr[j][i])
		{
			score++;
		}
		else{
			break;
		}
	}
	for (int i = numrow - 1, j = numcol - 2; i >= 0, j >= 0; i--, j--)
	{
		if (arr[numrow][numcol - 1] == arr[i][j])
		{
			score1++;
		}
		else{
			break;
		}
	}

	for (int i = numrow + 1, j = numcol; i < width, j < height; i++, j++)
	{
		if (arr[numrow][numcol - 1] == arr[i][j])
		{
			score1++;
		}
		else{
			break;
		}
	}
	if (score >= 3 || score1 >= 3)
	{
		win = 1;
	}
	return win;
}

bool check_all(int numcol)
{
	if (check_col(numcol) == 1)
	{
		return 1;
	}
	else if (check_row(numcol) == 1)
	{
		return 1;
	}
	else if (check_diagonal(numcol) == 1)
	{
		return 1;
	}
	else {
		return 0;
	}
}
bool end_game(int count)
{
	char ch;
	cout << "DO YOU LIKE TO PLAY AGAIN PRESS(Y/N): ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				arr[i][j] = 0;
			}
		}
		cout << "Do you want to play with the same players ? (y/n) ";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
		{
			choice();
		}
		system("cls");
		drawboard();
		if (count % 2 != 0)
		{
			cout << p1.name << " : ";
			cin >> numcol;
		}
		return 1;
	}
	else{
		return 0;
	}
}