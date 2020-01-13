#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	char selection;
	int num;

	do{
		cout << "MENU\n"
			<< "a) Generate Multiplication Table\n"
			<< "q) Quit the program\n"
			<< "Please make a selection : ";
		cin >> selection;

		while (selection != 'a' && selection != 'q'){
			cout << "\nInvalid selection. Try again." << endl;
			cout << "Please make another selection: ";
			cin >> selection;
		}

		//start
		if (selection == 'a'){
			cout << "Please enter a number for your multiplication table: ";
			cin >> num;
			cout << endl;

			while (num < 1 || num > 10) {
				cout << "Invalid number. Try again." << endl;
				cout << "Please enter another number: ";
				cin >> num;
				cout << endl;
			}

			//spacings
			for (int i = 1; i <= num; ++i) {
				cout << setw(3) << "    " << i;
			}
			cout << endl;
			cout << "   ";
			for (int i = 1; i <= num; ++i) {
				cout << setw(2) << "----|";
			}
			cout << endl;

			//algorithm
			for (int i = 1; i <= num; ++i) {
				cout << setw(2) << i << "| ";
				for (int j = 1; j <= num; ++j) {
					cout << setw(3) << i * j << "| ";
				}
				cout << endl;
				cout << " -|";
				for (int i = 1; i <= num; ++i) {
					cout << setw(2) << "----|";
				}
				cout << endl;
			}
		}
	} while (selection != 'q');

	cout << "\nYou have chosen to quit the program. Thank you for using!" << endl;

	system("pause");
	return 0;
}