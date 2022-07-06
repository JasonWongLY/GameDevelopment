#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include<sstream>
using namespace std;

//  Global Scope
int timelimit = 40;
int maxOrder = 5;
int mark = 10;
int order;
int tempOrder;
int stringToInt;

//  function prototypes
void gameMenu();
void intialOrder();
void orderList();
void process(int);
void score(int, int);
void checkScore();
void delOrder(int);
void addOrder();
bool isNum(string);
void burgerType();
void symbol();
void burgerMenu();
void setting();
void timeSetting();
void orderSetting();
void credits();
void Instructions();


class Burger										 // Burger Class
{
public:
	int burgerType;

	void resetStatus()								// use for reset the statusNo
	{
		statusNo = 1;
	}
	void startingTime()								// let current time be the startTime
	{
		int j;
		while (mark >= 0)
		{
			j = 1;
			if (j == 1)
			{
				startTime = time(0);
				j++;
			}

			break;

		}
	}

	void checkStatus(int m)							// check which status and call functions depend on which status
	{												// use for order list
		status();
		if (statusNo == 1)
		{

			process(m);
		}
		if (statusNo == 2)
		{
			cout << "the burger is still cooking" << endl;
			system("pause");
			orderList();
		}
		else if (statusNo == 3)
		{
			int x = 1;
			score(x, m);


		}

	}
	void delType()									// reset all the variable after the order is finished or failed
	{
		burgerType = 0;
		remainTime = 0;
		cookingtime = 0;
		cookingremainTime = 0;
		correctKey = false;
		cookingElapsedTime = 0;
		cookingStartTime = 0;
		statusNo = 1;
		order -= 1;
		
	}

	bool RemainTime0()								// check whether the remain order time is 0 ,if yes return false for delete the order and deduce marks
	{
		if (remainTime <= 0)
			return true;
		else
			return false;
	}

	void random()									// randomly generate the burger type
	{
		burgerType = 1 + rand() % 5;
	}

	void printName()								// print burger name
	{
		switch (burgerType) {
		case 1:cout << "Cheese Burger";
			break;
		case 2:cout << "Beef Burger";
			break;
		case 3:cout << "Mushroom Burger";
			break;
		case 4:cout << "Veggie Burger";
			break;
		case 5: cout << "Salmon Burger";
			break;
		case 0:
			break;
		}
	}

	void printKey()									// print the correct key for each burger
	{
		switch (burgerType) {
		case 1:cout << "bcflb" << endl;
			break;
		case 2:cout << "bctflb" << endl;
			break;
		case 3:cout << "bcfmb" << endl;
			break;
		case 4:cout << "btelb" << endl;
			break;
		case 5:cout << "bcfsb" << endl;
			break;
		case 0:
			break;
		}
	}

	void printInfo()									// print the information about each burger
	{
		switch (burgerType) {
		case 1:cout << "[B]read, [C]heese, Bee[f], [L]ettuce, [B]read" << endl;
			break;
		case 2:cout << "[B]read, [C]heese, [T]omato, bee[F], [L]ettuce, [B]read " << endl;
			break;
		case 3:cout << "[B]read, [C]heese, bee[F], [M]ushroom, [B]read" << endl;
			break;
		case 4:cout << "[B]read, [T]omato, [E]gg, [L]ettuce, [B]read " << endl;
			break;
		case 5:cout << "[B]read, [C]heese, bee[F], [S]almon, [B]read " << endl;
			break;
		case 0:
			break;
		}
	}

	void checkKey(string n)										// use for check the key from player input isn't correct
	{
		string key;
		switch (burgerType) {
		case 1: key = "bcflb";
			break;
		case 2: key = "bctflb";
			break;
		case 3: key = "bcfmb";
			break;
		case 4: key = "btelb";
			break;
		case 5: key = "bcfsb";
			break;
		case 0:
			break;
		}
		if (n == key)
		{
			correctKey = true;
			cookingStartTime = time(0);
			cookingTime();

		}
		else
		{
			cin.ignore();
		}
	}

	int remainTime;

	void timeLimit()													// calculate the remain order time
	{

		int elapsedTime = time(0) - startTime;
		remainTime = timelimit - elapsedTime;

	}

	void reset()														// reset 
	{
		correctKey = false;
	}

	void printime()														// print the remain order time
	{
		timeLimit();
		int remainder = remainTime % 3600;
		int minute = remainder / 60;
		int second = remainder % 60;
		cout << minute << ":" << second;
	}

	int cookingtime;
	int cookingremainTime;
	void cookingTime()													// set the cooking time and calculate the remain prder time
	{
		if (correctKey == false)
		{
			switch (burgerType) {
			case 1:cookingtime = 10;
				cookingElapsedTime = 0;
				cookingremainTime = 10;
				break;
			case 2:cookingtime = 10;
				cookingElapsedTime = 0;
				cookingremainTime = 10;
				break;
			case 3:cookingtime = 15;
				cookingElapsedTime = 0;
				cookingremainTime = 15;
				break;
			case 4:cookingtime = 10;
				cookingElapsedTime = 0;
				cookingremainTime = 10;
				break;
			case 5:cookingtime = 15;
				cookingElapsedTime = 0;
				cookingremainTime = 15;
				break;
			case 0:
				break;

			}

			status();
		}
		else if (correctKey == true)
		{
			switch (burgerType) {
			case 1:cookingtime = 10;
				break;
			case 2:cookingtime = 10;
				break;
			case 3:cookingtime = 15;
				break;
			case 4:cookingtime = 10;
				break;
			case 5:cookingtime = 15;
				break;
			case 0:
				break;
			}
			cookingElapsedTime = time(0) - cookingStartTime;
			cookingremainTime = cookingtime - cookingElapsedTime;
			status();
		}
	}

	void status()													// declare the status No. depends on the cooking remain time
	{
		switch (burgerType) {
		case 1:
		case 2:
		case 4:
			if (cookingremainTime >= 10)
			{
				statusNo = 1;

			}
			else if (cookingremainTime < 10 && cookingremainTime>0)
			{
				statusNo = 2;

			}
			else if (cookingremainTime <= 0)
			{
				statusNo = 3;

			}
			break;
		case 3:
		case 5:
			if (cookingremainTime >= 15)
			{
				statusNo = 1;

			}
			else if (cookingremainTime < 15 && cookingremainTime>0)
			{
				statusNo = 2;

			}
			else if (cookingremainTime <= 0)
			{
				statusNo = 3;

			}
			break;
		case 0:
			break;
		}
	}
	void showStatus()												// show the status depends on the status No.
	{
		if (statusNo == 1)
			cout << "Preparing";
		else if (statusNo == 2)
			cout << "Cooking";
		else if (statusNo == 3)
			cout << "Ready to serve";
	}
private:



	int statusNo = 1;
	bool correctKey = false;

	int cookingElapsedTime = 0;
	int cookingStartTime;
	int startTime;

};

Burger x[51] = {};

void delOrder(int y)												// use for del the order when the order is finished or failed
{
	for (int i = y; i < order; i++)  //read array
	{
		for (int j = 0; (i + j + 1 <= i + 1); j++)   //change
		{
			x[i + j] = x[i + j + 1];
		}
	}
	x[order + 1].delType();
}

void showList()									// show the Game menu
{
	system("cls");
	cout << "*** Game Menu ***" << endl;
	cout << "[1] Start Game" << endl;
	cout << "[2] Settings" << endl;
	cout << "[3] Burger Menus" << endl;
	cout << "[4] Instructions" << endl;
	cout << "[5] Credits" << endl;
	cout << "[6] Exit" << endl;
	cout << "****************************" << endl;

}

void intialOrder()		// randon genarate a intial order
{
	srand(time(0));
	order = 1 + rand() % maxOrder;
}

void gameMenu()											// Game Menu 
{
	int option;
	showList();
	cout << "Option (1 - 6) : ";
	cin >> option;
	if (cin.fail()) {
		cout << "Enter the integer within 1-6!"<<endl;
		system("pause");
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');
		
		gameMenu();
	}


	switch (option)
	{
	case 1:
		mark = 10;

		intialOrder();
		for (int i = 1; i <= order; i++) {       //random generate the type of burger for intial order
			srand(i*time(0));
			x[i].random();
			x[i].reset();
			x[i].cookingTime();
			x[i].startingTime();
		}

		orderList();
		break;
	case 2:
		setting();
		break;
	case 3:
		burgerMenu();
		break;
	case 4:
		Instructions();
		break;
	case 5:
		credits();
		break;
	case 6:
		cout << "Goodbye!";
		exit(0);
		break;
		
		
	default:
		cout << "Enter the integer within 1-6!"<<endl;
		system("pause");
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');

		gameMenu();
		break;

	}

}

void orderList()							// Order List
{


	system("cls");
	checkScore();
	for (int i = 1; i <= order; i++)
	{


		x[i].timeLimit();
		if (x[i].RemainTime0() == true)
		{
			int k = 0;
			score(k, i);
		}

		cout << "Order #" << i << ": ";
		x[i].printName(); cout << ", ";

		x[i].cookingTime();

		x[i].showStatus();
		cout << ", ";
		x[i].printime();
		cout << endl;

	}
	cout << "----------------------------------" << endl;
	cout << "Score: " << mark << endl;
	cout << "Enter [U] for update, [Q] for Quit, or [1-5] for order: ";
	string n;

	do
	{
		cin >> n;

		if (isNum(n) == true)
		{
			stringToInt = stoi(n);
			if (stringToInt > 0 && stringToInt <= order)
			{
				x[stringToInt].checkStatus(stringToInt);

			}
			else
			{
				cin.ignore(1024, '\n');
				cout << "Wrong Input!";
				system("pause");
				cout << endl;
				orderList();
			}
		}
		else if (n == "q" || n == "Q")
		{
			string choose;
			cout << "Do you really want to exit? Please enter [Y/N]:";
			cin >> choose;
			if (choose == "Y" || choose == "y")
			{
				gameMenu();
			}
			else if (choose == "n" || choose == "N")
			{
				orderList();
			}
			else
			{
				cout << "Please enter the correct choice." << endl;
				system("pause");
				orderList();
			}
		}
		else if (n == "u" || n == "U") {
			system("cls");
			checkScore();
			if (order <= maxOrder)
			{
				for (int i = order + 1; i <= maxOrder; i++)
				{
					addOrder();
					
					x[i].startingTime();

				}

			}
			for (int i = 1; i <= order; i++)
			{
				x[i].timeLimit();
				if (x[i].RemainTime0() == true)
				{
					int k = 0;
					score(k, i);
				}
				cout << "Order #" << i << ": ";
				x[i].printName(); cout << ", ";
				x[i].cookingTime();

				x[i].showStatus();
				cout << ", ";
				x[i].printime();
				cout << endl;
			}
			cout << "----------------------------------" << endl;
			cout << "Score: " << mark << endl;
			cout << "Enter [U] for update, [Q] for Quit, or [1-5] for order: ";
		}


		else
		{
			cin.ignore(1024, '\n');
			cout << "Wrong Input!";
			system("pause");
			cout << endl;
			orderList();
		}


	} while (mark >= 0);
}

bool isNum(string str)									// use for check whether the value stored in string is a num
{
	stringstream sin(str);
	double d;
	char c;
	if (!(sin >> d))
	{
		return false;
	}
	if (sin >> c)
	{
		return false;
	}
	return true;
}

void checkScore()														// end the game when mark < 0 and win the game when mark reached 100
{
	if (mark < 0)
	{
		cout << "Game over!!" << endl;
		system("pause");
		gameMenu();
	}
	else if (mark > 99)
	{
		system("cls");
		cout << "You win!!" << endl;
		system("pause");
		gameMenu();
	}
}
void score(int x, int y)												// use for calculate the marks when the order is successed or failed
{																		
	
		switch (x)
		{
		case 1:
			mark += 10;
			delOrder(y);
			orderList();
			break;
		case 0:
			mark -= 5;
			delOrder(y);
			orderList();
			break;
		}


	

}

void addOrder()												// generate new order
{
	tempOrder = order;
	int percentage = 1 + rand() % 10;
	if (percentage >= 1 && percentage <= 5)
	{
		order += 1;
	}
	for (int i = tempOrder + 1; i <= order; i++)
	{
		
		x[i].random();
		x[i].reset();
		x[i].cookingTime();
	}
}

void process(int i)															// process List
{
	int j = i;
	system("cls");
	cout << "* Process Order *" << endl;
	cout << "Order #" << right << setw(17) << ": " << i << endl;
	cout << "Burger" << right << setw(18) << ": "; x[i].printName(); cout << endl;
	cout << "Status" << right << setw(18) << ": "; x[i].showStatus(); cout << endl;
	cout << "Remaining Time" << right << setw(10) << ": "; x[i].printime(); cout << endl;
	cout << "Burger Ingredient List: "; x[i].printInfo();
	cout << "Burger Key List" << right << setw(9) << ": "; x[i].printKey();
	cout << endl;
	cout << "Please choose [U] for update, [R] for return, or " << endl << "type correct key list to start cooking: ";
	string n;
	cin >> n;

	if (n == "u" || n == "U") {
		system("cls");
		process(j);
	}
	else if (n == "r" || n == "R")
	{
		orderList();
	}

	else if (n == "bcflb" || n == "bctflb" || n == "bcfmb" || n == "btelb" || n == "bcfsb")
	{
		x[i].checkKey(n);
		system("pause");
		orderList();

	}
	else
	{
		cout << "Incorrect Input! Please input again!" << endl;
		system("pause");
		process(j);
	}
}

// option 2
void setting()										// setting List
{
	int option;
	system("cls");
	cout << "*** Settings Menu ***" << endl;
	cout << "[1] Time limit [" << timelimit << " sec]" << endl;
	cout << "[2] Max number of orders [" << maxOrder << "]" << endl;
	cout << "[3] Return to Game Menu" << endl;
	cout << "*********************" << endl;
	cout << "Option (1 - 3):";
	cin >> option;
	switch (option)
	{
	case 1:timeSetting();
		break;
	case 2:orderSetting();
		break;
	case 3:	gameMenu();
		break;
	default:
		cout << "Enter the integer within 1-3!" << endl;
		system("pause");
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');
		setting();
	}
}

void timeSetting()											// time setting
{
	string option;
	system("cls");
	cout << "The current time limit: " << timelimit << " sec" << endl;
	cout << "Please enter the new time limit within the range 40-300 sec" << endl;
	cout << "Or press q/Q return to Settings Menu" << endl;
	cout << "***********************************************************" << endl;
	cout << "Option :";
	cin >> option;
	if (isNum(option) == true) {
		stringToInt = stoi(option);
		if (stringToInt >= 40 && stringToInt <= 300)
		{
			timelimit = stringToInt;
			setting();
		}
	}
	else if (option == "q"||option=="Q")
	{
		setting();
	}
	else
	{
		cout << "Invalid input! Please input again!" << endl;
		system("pause");
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');
		timeSetting();
	}
}

void orderSetting()														// maximun order number setting
{
	string option;
	system("cls");
	cout << "The current max order number: " << maxOrder << endl;
	cout << "Please enter the new max order number within the range 1-50 sec" << endl;
	cout << "Or press q/Q return to Settings Menu" << endl;
	cout << "***********************************************************" << endl;
	cout << "Option :";
	cin >> option;
	if (isNum(option) == true) {
		stringToInt = stoi(option);
		if (stringToInt >= 1 && stringToInt <= 50)
		{
			maxOrder = stringToInt;
			setting();
		}
	}
	else if (option == "q"||option=="Q")
	{
		setting();
	}
	else
	{
		cout << "Invalid input! Please input again!" << endl;
		system("pause");
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');
		orderSetting();
	}
}


// option 3
void burgerType()									// burger typr list
{
	system("cls");
	cout << left << setw(20) << "Type of burgers" << left << setw(45) << "Ingredients orders" << "Cooking time" << endl;
	cout << left << setw(20) << "Cheese burger" << left << setw(45) << "Bread, cheese, beef, lettuce, bread" << "10" << endl;
	cout << left << setw(20) << "Beef burger" << left << setw(45) << "Bread, cheese, tomato, beef, lettuce, bread" << "10" << endl;
	cout << left << setw(20) << "Mushroom burger" << left << setw(45) << "Bread, cheese, beef, mushroom, bread" << "15" << endl;
	cout << left << setw(20) << "Veggie burger" << left << setw(45) << "Bread, tomato, egg, lettuce, bread" << "10" << endl;
	cout << left << setw(20) << "Salmon burger" << left << setw(45) << "Bread, cheese, beef, salmon, bread" << "15" << endl;
	system("pause");
	burgerMenu();
}

void symbol()											// burger symbol list
{
	system("cls");
	cout << left << setw(14) << "Ingredients" << left << setw(10) << "Symbol" << left << setw(14) << "Ingredients" << left << setw(10) << "Symbol" << endl;
	cout << left << setw(14) << "Bread" << left << setw(10) << "B/b" << left << setw(14) << "Tomato" << left << setw(10) << "T/t" << endl;
	cout << left << setw(14) << "Cheese" << left << setw(10) << "C/c" << left << setw(14) << "Mushroom" << left << setw(10) << "M/m" << endl;
	cout << left << setw(14) << "Beef" << left << setw(10) << "F/f" << left << setw(14) << "Egg" << left << setw(10) << "E/e" << endl;
	cout << left << setw(14) << "Lettuce" << left << setw(10) << "L/l" << left << setw(14) << "Salmon" << left << setw(10) << "S/s" << endl;
	system("pause");
	burgerMenu();
}

void burgerMenu()													// burger menu
{
	int n;
	system("cls");
	cout << "**** Burger Menu *****" << endl;
	cout << "[1] Types of Burger\n[2] Ingredient Symbols\n[3] Return to Game Menu\n" << string(21, '*') << endl;
	cout << "Option ( 1 - 3 ): ";
	cin >> n;
	switch (n) {
	case 1:
		burgerType();
		break;

	case 2:
		symbol();
		break;

	case 3:
		gameMenu();
		return;
		break;
	default:
		cout << "Please enter the number within 1 and 3!" << endl;
		system("pause");
	
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');
		burgerMenu();

	}
}

// option 4 Instruction
void Instructions()
{
	system("cls");
	cout << "Instruction:" << endl;
	cout << "[1]Start Game" << endl;
	cout << "[2]Order list" << endl;
	cout << "[3]New order generation" << endl;
	cout << "[4]Time limit" << endl;
	cout << "[5]Game rules / Scoring" << endl;
	cout << "[6]Quit the game" << endl;
	cout << "****************************" << endl;
	cout << "Enter 1-6 for checking the detail \nOr enter q/Q back to Game List : ";
	string option;
	cin >> option;

	if (isNum(option) == true)
	{
		if (option == "1") {
			system("cls");
			cout << "This is a game for cooking a burger." << endl;
			cout << "Start Game" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "First, you should press the key [1] for start game." << endl;
			cout << "Second, it will randomly show the order list of each burger." << endl;
			cout << "Third, Player can input the order number to process the order." << endl;
			cout << "Fourth, Player can input [u] or [U] to refresh the order list for updating the information of all orders." << endl;
			cout << "Player can input [q] or [Q] to quit the current game and return to the game menu." << endl;
			system("pause");
			Instructions();
		}

		if (option == "2") {
			system("cls");
			cout << "Order list" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Player can input the order number to choose the order with status [preparing]." << endl;
			cout << "Then the [Process Order] page will be shown. " << endl;
			system("pause");
			Instructions();
		}

		if (option == "3") {
			system("cls");
			cout << "New order generation" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Player can input [u] or [U] to refresh the remaining time of the order." << endl;
			cout << "Player can input [q] or [Q] to return to the order list." << endl;
			cout << "New orders are generated randomly with a certain probability" << endl;
			cout << "Player needs to type the correct order of ingredient symbols." << endl;
			system("pause");
			Instructions();
		}

		if (option == "4") {
			system("cls");
			cout << "Time limit" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "There is a time limit for each order, which is the same for all types of burger and can be set in the game settings" << endl;
			cout << "The orders need to be served before the time limit is reached." << endl;
			cout << "The remaining time shown in the order list will be updated every time the order list is" << endl;
			cout << "refreshed, e.g.player inputs [u] or [U] to update the order list, an order is served, or" << endl;
			cout << "the program returns from the [process order] page." << endl;
			system("pause");
			Instructions();
		}

		if (option == "5") {
			system("cls");
			cout << "Game rules / Scoring" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "When the game starts, the player will initially have 10 marks." << endl;
			cout << "- If the order is served on time, 10 marks will be awarded." << endl;
			cout << "- When the order cannot be served within the time limit, 5 marks will be deducted." << endl;
			cout << "The game lose when the score < 0. If the player lose, the system will be notice." << endl;
			cout << "The game Win when the score >= 100. If the player win, the system will be notice." << endl;
			cout << "the player, and the program returns to the Game Menu." << endl;
			system("pause");
			Instructions();
		}

		if (option == "6") {
			system("cls");
			cout << "Quit the game" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Player can input [q] or [Q] in the order list page to quit the game." << endl;
			system("pause");
			Instructions();
		}
		else
		{
			cout << "Invalid input! Please input again!" << endl;
			system("pause");
			cin.clear();
			cin.sync();
			cin.ignore(1024, '\n');
			Instructions();
		}
	}
	else if (option == "q" || option == "Q")
		gameMenu();
	else
	{
		cout << "Invalid input! Please input again!" << endl;
		system("pause");
		cin.clear();
		cin.sync();
		cin.ignore(1024, '\n');
		Instructions();
	}
}


// option 5 Credits
void credits() 
{
	system("cls");
	cout << left << setw(20) << "Student Name" << left << setw(15) << "Student ID" << "Class" << endl;
	cout << "----------------------------------------" << endl;
	cout << left << setw(20) << "Chow Hiu Chun" << left << setw(15) << "18105198A" << "204A" << endl;
	cout << left << setw(20) << "Luk Chok Hong" << left << setw(15) << "18050957A" << "204B" << endl;
	cout << left << setw(20) << "Tang Ching Ngai" << left << setw(15) << "18094075A" << "204B" << endl;
	cout << left << setw(20) << "Tse Kit Ho" << left << setw(15) << "18098873A" << "204B" << endl;
	cout << left << setw(20) << "Wong Lap Yin" << left << setw(15) << "18057319A" << "204A" << endl;
	system("pause");
	gameMenu();
}

int main()													// main function with cout the wewlcome message 
{
	cout << "Welcome to the Cooking MaMa." << endl; 
	cout << "Try to get 100 marks in the game." << endl;
	cout << "Have Fun!" << endl;
	Sleep(2000);
	gameMenu();
	return 0;
}