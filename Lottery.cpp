#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void getLottoPicks(int[], int);
void genWinNums(int[], int);
void sortArray(int[], int);
void noDuplicate(int[], int);
void noDuplicateRand(int[], int);
int isWinner(int[], int[], int);
void numMatches(int);

int main()
{
	const int LOTNUM = 7;

	//set user array
	int UserTicket[LOTNUM];

	//call
	getLottoPicks(UserTicket, LOTNUM);

	//print UserTicket
	cout << "User pick: ";
	for (int i = 0; i < LOTNUM; ++i) {
		cout << UserTicket[i] << " ";
	}
	
	//set rand array
	int WinningNum[LOTNUM];

	//call
	genWinNums(WinningNum, LOTNUM);

	//print WinningNums
	cout << "Win numbers: ";
	for (int i = 0; i < LOTNUM; ++i) {
		cout << WinningNum[i] << " ";
	}
	cout << endl << endl;

	//sort the array
	sortArray(UserTicket, LOTNUM);
	sortArray(WinningNum, LOTNUM);

	//check for duplicates
	noDuplicate(UserTicket, LOTNUM);
	noDuplicateRand(WinningNum, LOTNUM);

	//sort array again
	sortArray(UserTicket, LOTNUM);
	sortArray(WinningNum, LOTNUM);

	//print out sorted array - ascending
	for (int i = 0; i < LOTNUM; ++i) {
		cout << UserTicket[i] << " ";
	}
	cout << endl;

	//print out sorted random array - ascending
	for (int i = 0; i < LOTNUM; ++i) {
		cout << WinningNum[i] << " ";
	}
	cout << endl;

	//check to see how many matches
	int matches;
	matches = isWinner(UserTicket, WinningNum, LOTNUM);
	//cout << matches << endl;

	//prizes
	numMatches(matches);

	system("pause");
	return 0;
}

//getLottoPicks = return array
void getLottoPicks(int User[], int NUM) {
	cout << "Enter your picks" << endl;
	for (int i = 0; i < NUM; ++i) {
		cin >> User[i];
	}
	/*for (int i = 0; i < NUM; ++i) {
		cout << User[i] << " ";
	}*/
	cout << endl;
}
void genWinNums(int Win[], int NUM) {
	//set srand() once
	srand((unsigned int)time(NULL));

	//set rand values
	for (int i = 0; i < NUM; ++i) {
		Win[i] = rand() % 100 + 1;
	}

	/*for (int i = 0; i < NUM; ++i) {
		cout << Win[i] << " ";
	}*/
	cout << endl;
}
void sortArray(int ary[], int NUM) {
	int temp;
	for (int i = 0; i < NUM; ++i) {
		for (int j = i + 1; j < NUM; ++j) {
			if (ary[i] > ary[j]) { 
				temp = ary[i];	
				ary[i] = ary[j]; 
				ary[j] = temp;

			}
		}
	}
}
void noDuplicate(int ary[], int NUM) {
	for (int i = 0; i < NUM; ++i) {
		for (int j = i + 1; j < NUM; ++j) {
			if (ary[i] == ary[j]) {
				cout << "Enter another number" << endl;
				cin >> ary[i];
			}
		}
	}
}
void noDuplicateRand(int ary[], int NUM) {

	srand((unsigned int)time(NULL));

	for (int i = 0; i < NUM; ++i) {
		for (int j = i + 1; j < NUM; ++j) {
			if (ary[i] == ary[j]) {
				cout << "Re-rolling randoms" << endl;
				ary[i] = rand() % 100 + 1;
			}
		}
	}
}
int isWinner(int user[], int rand[], int NUM) {
	int match = 0;
	for (int i = 0; i < NUM; ++i) {
		for (int j = i + 1; j < NUM; ++j) {
			if (user[i] == rand[j]) {
				cout << user[i] << " matched with " << rand[j] << endl;
				match++;
			}
		}
	}
	cout << "Total matches in all: " << match << endl;
	return match;
}
void numMatches(int num) {
	if (num == 7) {
		cout << "JACKPOT!" << endl;
	}
	else if (num == 6) {
		cout << "GREAT!" << endl;
	}
	else if (num == 5) {
		cout << "LUCKY YOU" << endl;
	}
	else if (num == 4) {
		cout << "NOT BAD" << endl;
	}
	else if (num == 3) {
		cout << "FREE TICKET" << endl;
	}
	else {
		cout << "SORRY, NOTHING" << endl;
	}
}
