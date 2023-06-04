#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> towerA{ 3,2,1 };
vector<int> towerB{ 0,0,0 };
vector<int> towerC{ 0,0,0 };

int towerLength = 3;
int level = 1;

int moves = (pow(2, towerLength)) - 1;


void print_tower(vector<int> tower) {
	for (int i = 0; i < towerLength; i++) {
		cout << tower[i] << "\t";
	}
	cout << endl;
}

bool checkContinue(string str) {
	if (str == "1") {
		return (true);
	}
	else {
		string str2;
		cout << "please enter the correct number : ";
		getline(cin, str2);
		checkContinue(str2);
	}
}

vector<int> foundTower(string tower) {
	if (tower == "A")
	{
		return(towerA);
	}
	else if (tower == "B") {
		return(towerB);
	}
	else if (tower == "C") {
		return(towerC);
	}
}

void updateTower(vector<int> newTower, string towerName) {
	if (towerName == "A") {
		towerA = newTower;
	}
	else if (towerName == "B") {
		towerB = newTower;
	}
	else if (towerName == "C") {
		towerC = newTower;
	}
}

void change_tower(string first, string second, int num) {
	vector<int> firstVector = foundTower(first);
	vector<int> secondVector = foundTower(second);
	bool validNum = false;
	for (int i = towerLength - 1; i >= 0; i--) {
		if (firstVector[i] != 0) {
			if (firstVector[i] == num)
			{
				for (int j = 0; j < towerLength; j++)
				{
					if (secondVector[j] == 0) {
						if (j == 0) {
							firstVector[i] = 0;
							secondVector[j] = num;
							updateTower(firstVector, first);
							updateTower(secondVector, second);
							break;
						}
						else {
							if (num < secondVector[j - 1]) {
								firstVector[i] = 0;
								secondVector[j] = num;
								updateTower(firstVector, first);
								updateTower(secondVector, second);
								break;
							}
							else {
								cout << "This number is biger than the number inside tower" << endl;
								moves++;
								string cont;
								cout << "Please enter number 1 to continue : ";
								getline(cin, cont);
								checkContinue(cont);
								break;
							}
						}

					}
				}
				validNum = true;
			}
			break;
		}
	}
	if (!validNum) {
		cout << "This number is invalid!" << endl;
		string cont;
		cout << "Please enter number 1 to continue : ";
		getline(cin, cont);
		checkContinue(cont);
		moves++;
	}
}

bool checkValiditiTower(string tower) {
	if (tower == "A" || tower == "a" || tower == "B" || tower == "b" || tower == "C" || tower == "c" && tower.length() == 1) {
		return(false);
	}
	else {
		return(true);
	}
}

bool checkValiditiTower(string tower, string firstTower) {
	if (tower == "A" || tower == "a" || tower == "B" || tower == "b" || tower == "C" || tower == "c" && tower.length() == 1) {
		tower = (char)toupper(tower[0]);
		if (tower == firstTower) {
			return(true);
		}
		else {
			return(false);
		}
	}
	else {
		return(true);
	}
}

bool checkValiditiNum(string num) {
	if (num.length() != 1) {
		return(false);
	}
	else {
		int number = toupper(num[0]) - 48;
		if (number > towerLength || number < 1) {
			return(false);
		}
	}
}

void resetTowers() {
	for (int i = 0; i < towerLength - 1; i++)
	{
		towerA[i] = towerC[i];
		towerB[i] = 0;
		towerC[i] = 0;
	}
	towerA.insert(towerA.begin(), towerLength);
	towerB.push_back(0);
	towerC.push_back(0);
}

bool checkLose() {
	if (moves == 0) {
		cout << "----------You lose the game----------" << endl;
		cout << "A :\t";
		print_tower(towerA);

		cout << "B :\t";
		print_tower(towerB);

		cout << "C :\t";
		print_tower(towerC);

		for (int i = 0; i < towerLength; i++)
		{
			towerA[i] = towerLength - i;
			towerB[i] = 0;
			towerC[i] = 0;
		}
		moves = (pow(2, towerLength)) - 1;
		return(true);
	}
	else {
		return(false);
	}
}

bool checkWin() {
	bool valid = true;
	int num = towerLength;
	for (int i = 0; i < towerLength; i++)
	{
		if (towerC[i] != num) {
			valid = false;
			break;
		}
		num--;
	}
	if (valid) {
		cout << "----------You win the game----------" << endl;
		cout << "A :\t";
		print_tower(towerA);

		cout << "B :\t";
		print_tower(towerB);

		cout << "C :\t";
		print_tower(towerC);

		level++;
		towerLength++;
		resetTowers();

		moves = (pow(2, towerLength)) - 1;
	}
	return (valid);
}

int main()
{
	cout << "---------- Hanoi Tower ----------" << endl;
	while (true) {
		system("cls");
		string user_choise;
		cout << "----------Level : " << level << "----------" << endl;
		cout << "1) Start\n2) Help\n3) Exit\nChoose your option : ";
		//cin >> user_choise;
		getline(cin, user_choise);
		if (user_choise == "1") {
			while (true) {
				system("cls");
				if (checkWin()) {
					string cont;
					cout << "Please enter number 1 to continue : ";
					getline(cin, cont);
					checkContinue(cont);
					break;
				}
				else if (checkLose()) {
					string cont;
					cout << "Please enter number 1 to continue : ";
					getline(cin, cont);
					checkContinue(cont);
					break;
				}
				cout << "----------Moves : " << moves << "----------" << endl;

				cout << "A :\t";
				print_tower(towerA);

				cout << "B :\t";
				print_tower(towerB);

				cout << "C :\t";
				print_tower(towerC);

				cout << "choose your beginning tower : ";
				string beginning_tower;
				//cin >> beginning_tower;
				getline(cin, beginning_tower);

				while (true) {
					if (checkValiditiTower(beginning_tower)) {
						cout << "Please enter a valid tower : ";
						getline(cin, beginning_tower);
					}
					else {
						beginning_tower = (char)toupper(beginning_tower[0]);
						break;
					}
				}

				cout << "choose your number : ";
				string number;
				//cin >> number;
				getline(cin, number);
				char number_choise;
				while (true) {
					if (!checkValiditiNum(number)) {
						cout << "Please enter a valid number : ";
						getline(cin, number);
					}
					else {
						number_choise = number[0];
						number_choise = (int)number_choise - 48;
						break;
					}
				}

				cout << "choose your target tower : ";
				string target_tower;
				//cin >> target_tower;
				getline(cin, target_tower);
				while (true) {

					if (checkValiditiTower(target_tower, beginning_tower)) {
						cout << "Please enter a valid tower : ";
						getline(cin, target_tower);
					}
					else {
						target_tower = (char)toupper(target_tower[0]);
						break;
					}
				}

				change_tower(beginning_tower, target_tower, number_choise);
				moves--;
			}
		}
		else if (user_choise == "2") {
			system("cls");
			cout << "Welcome to Tower of Hanoi game. In this game, you have to move the pieces from tower A to tower C by observing the following two rules:"
				<< "\n1 - You can only move one bead in each step"
				<< "\n2 - You cannot place the bigger bead on the smaller bead" << endl;
			cout << "Enter a key to exit : ";
			string exit;
			//cin >> exit;
			getline(cin, exit);
			continue;
		}
		else if (user_choise == "3") {
			break;
		}
		else {
			cout << "The number entered is not valid! " << endl;
			string cont;
			cout << "Please enter number 1 to continue : ";
			getline(cin, cont);
			checkContinue(cont);
		}
	}
}
