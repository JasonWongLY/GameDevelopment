#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int diff = 3;
int countmove = 0;
//prototype
void startgame();
void MainMenu();
void confirmleave();
void print();
void input();
void roddata(char,char);
int whichrod(char);
void perform(int,int,int,int);
void congratulations();
class rod
{
public:
	int x[11] = {0,0,0,0,0,0,0,0,0,0,0};

	void set(int a)
	{
		for (int i = 1; i <= a; i++)
		{
			x[i] = i;
		}
	}

	string display(int n)
	{
		switch (n)
		{
		case 0:
			return  " ";
			break;
		case 1:
			return "o";
			break;
		case 2:
			return "oo";
			break;
		case 3:
			return "ooo";
			break;
		case 4:
			return "oooo";
			break;
		case 5:
			return "ooooo";
			break;
		case 6:
			return "oooooo";
			break;
		case 7:
			return "ooooooo";
			break;
		case 8:
			return "oooooooo";
			break;
		case 9:
			return "ooooooooo";
			break;
		case 10:
			return "oooooooooo";
			break;
		default:
			cout << "You should not see this message!!" << endl;
			break;
		}
	}
	void printdisk(int level)
	{
		cout << setw(diff+1) << right << display(x[level]);
		if (x[level] > 0)
			cout << "o";
		else if (x[level] == 0)
			cout << "|";
		cout << setw(diff + 1) << left << display(x[level]);
	}

	
	int showvalue(int i)
	{
		return x[i];
	}
	
	void changedisk(int position,int value)
	{
		x[position] = value;
	}
	void topdisk(int& compare,int& position)
	{
		for (int i = 1; i <= diff; i++)
		{
			if (x[i] > 0)
			{
				compare = x[i];
				position = i;
				break;
			}
			if (i == diff && compare == 0)
			{

				cout << "This rod have no disk. Please Input again!!!";
				system("pause");
				startgame();
			}
		}
	}
	void lastdisk(int& compare, int& position)
	{
		for (int i = 1; i <= diff; i++)
		{
			if (x[i] > 0)
			{
				compare = x[i];
				position = i - 1;
				break;
			}
		}
	}
	bool checkresult()
	{
		
		for (int i = 1; i <= diff; i++)
		{
			if (x[i] != i)
			{
				break;
			}
			else if ((i == diff) && (x[i] == i))
			{
				return false;
			}
		}
	}
	void reset()
	{
		for (int i = 0; i <= 10; i++) \
		{
			x[i] = '\0';
		}
	}
private:

};

rod A, B, C;
void confirmleave()
{
	system("cls");
	char x;
	cout << "Do you really want to leave the game?" << endl;
	cout << "All the process will not be saved." << endl;
	cout << "Please input \"Y\" to leave OR \"N\" keep on playing the game." << endl;
	cin >> x;
	if ((x == 'Y') || (x == 'y'))
	{
		system("cls");
		A.reset();
		B.reset();
		C.reset();

		MainMenu();
	}
	else if ((x == 'N') || (x == 'n'))
	{
		system("cls");
		startgame();
	}
	else
	{
		system("cls");
		cout << "Please input \"Y\"/\"N\"!!!";
		system("pause");
		confirmleave();
	}
}
void print()
{
	cout << setw(diff + 1) << " " << "|" << setw((diff + 1) * 2) << " " << "|" << setw((diff + 1) * 2) << " " << "|" << endl;
	for (int i = 1; i <= diff; i++)
	{
		A.printdisk(i);
		B.printdisk(i);
		C.printdisk(i);
		cout << endl;
	}
	for (int i = 1; i <= 3; i++)
	{
		cout << setw(diff + 1) << right << "====";
		cout << "=";
		cout << setw(diff + 1) << left << "====";
	}
	cout << endl;
	cout << setw(diff + 1) << " " << "A" << setw((diff + 1) * 2) << " " << "B" << setw((diff + 1) * 2) << " " << "C" << endl;


}
int whichrod(char x)
{
	int a;

	switch (x)
	{
	case 'A':
	case 'a':
		a = 1;
		break;
	case 'B':
	case 'b':
		a = 2;
		break;
	case 'C':
	case 'c':
		a = 3;
		break;
	default:
		cout << "You should not see this message!!!" << endl;
		break;
	}
	return a;
}
void roddata(char x, char y)
{
	int compare1 = 0, compare2 = 0;
	int position1 = diff, position2 = diff;

	int rod1 = whichrod(x);
	if (rod1 == 1)
		A.topdisk(compare1,position1);
	else if (rod1 == 2)
		B.topdisk(compare1,position1);
	else if (rod1 == 3)
		C.topdisk(compare1,position1);
	
	int rod2 = whichrod(y);
	if (rod2 == 1)
		A.lastdisk(compare2, position2);
	else if (rod2 == 2)
		B.lastdisk(compare2, position2);
	else if (rod2 == 3)
		C.lastdisk(compare2, position2);

	if (compare2 == 0)
	{
		perform(rod1, rod2, position1, position2);
	}
	else if (compare1 < compare2)
	{
		perform(rod1, rod2, position1, position2);
	}
	else
	{
		system("cls");
		cout << "No disk can be placed on top of a smaller disk.";
		system("pause");
		startgame();
	}
	startgame();
}
void perform(int rod1,int rod2,int position1,int position2)
{
	switch (rod1)
	{
	case 1:
		switch (rod2)
		{
		case 2:
			B.changedisk(position2,A.showvalue(position1));
			A.changedisk(position1 , 0);
			countmove++;
			break;
		case 3:
			
			C.changedisk(position2, A.showvalue(position1));
			A.changedisk(position1, 0);
			countmove++;
			break;
		}
		break;
	case 2:
		switch (rod2)
		{
		case 1:
			
			A.changedisk(position2, B.showvalue(position1));
			B.changedisk(position1, 0);
			countmove++;
			break;
		case 3:
			
			C.changedisk(position2, B.showvalue(position1));
			B.changedisk(position1, 0);
			countmove++;
			break;
		}
		break;
	case 3:
		switch (rod2)
		{
		case 1:
			
			A.changedisk(position2, C.showvalue(position1));
			C.changedisk(position1, 0);
			countmove++;
			break;
		case 2:
			
			B.changedisk(position2, C.showvalue(position1));
			C.changedisk(position1, 0);
			countmove++;
			break;
		}
		break;
	}
}
void checkinput(char x)
{
	if ((x != 'a') && (x != 'A') && (x != 'b') && (x != 'B') && (x != 'c') && (x != 'C'))
	{
		system("cls");
		cout << "Please input A / B / C !!!";
		system("pause");
		startgame();
	}
}
void input()
{
	char x, y;
	cout << "Please input A / B / C to move a disk." << endl;
	cout << "e.g. \"A B\" means move a disk from rod A to rod B." << endl;
	cin >> x;
	
	if ((x == 'Q') || (x == 'q'))
	{
		confirmleave();
	}
	else
		checkinput(x);
	cin >> y;
		checkinput(x);
	if (x == y)
	{
		system("cls");
		cout << "Please input different chracter !!!";
		system("pause");
		startgame();
	}
	roddata(x,y);
}
void startgame()
{
	system("cls");
	print();
	if (C.checkresult() == 0)
		congratulations();
	input();
}
void congratulations()
{
	system("cls");
	cout << "Congratulations!!!!!\nYou Have successfully finished the game with " << countmove << " move!!!" << endl;
	cout << "Press any keys to back Main Menu." << endl;
	system("pause");
	A.reset();
	B.reset();
	C.reset();
	MainMenu();
}
void ChangeLevel()
{
	system("cls");
	int level;
	cout << "Current game level: " << diff << endl;
	cout << "The level of the game is in the range 1 to 10" << endl;
	cout << "Please enter the level you want to change: ";
	cin >> level;
	if ((level > 0) && (level < 11))
	{
		system("cls");
		cout << "You have successfully changed the game level from " << diff << " to " << level << endl;
		diff = level;
		system("pause");
		MainMenu();
	}
	else
	{
		system("cls");
		cout << "Please enter the integer in the range 1 to 10!!!" << endl;
		system("pause");
		ChangeLevel();
	}
}
void Credit()
{
	system("cls");
	cout << setw(20) << left << "Student Name" << setw(15) << left << "| Student No." << setw(6) << left << "| Class" << endl;
	cout << "--------------------+--------------+------" << endl;
	cout << setw(20) << left << "Chan Siu Ming" << setw(15) << left << "| 18000000A" << setw(6) << left << "| 101A" << endl;
	system("pause");
	MainMenu();
}
void Exit()
{
	system("cls");
	char choose;
	cout << "Do you really want to leave???" << endl;
	cout << "Please enter Y/y to confirm leaving OR enter N/n back to Main Menu.";
	cin >> choose;
	if ((choose == 'Y') || (choose == 'y'))
	{
		system("cls");
		cout << "OK...See you again~~~" << endl;

	}
	else if ((choose == 'N') || (choose == 'n'))
		MainMenu();
	else
	{
		system("cls");
		cout << "Please enter Y/y OR N/n!!!" << endl;
		system("pause");
		Exit();
	}
}
void MainMenu()
{
	system("cls");
	char choose;

	cout << "Welcome!" << endl;
	cout << "*** Main Menu ***" << endl;
	cout << "[1] Start Game" << endl;
	cout << "[2] Change Level" << endl;
	cout << "[3] Credits" << endl;
	cout << "[4} Exit" << endl;
	cout << "*****************" << endl;
	cout << "Option (1-4): ";
	cin >> choose;

	switch (choose)
	{
	case '1':
		A.set(diff);
		startgame();
		break;
	case '2':
		ChangeLevel();
		break;
	case '3':
		Credit();
		break;
	case '4':
		Exit();
		break;
	default:
		system("cls");
		cout << "Please input the integer between 1 to 4!!! ";
		system("pause");
		MainMenu();
		break;
	}

}

int main()
{
	MainMenu();
	return 0;
}