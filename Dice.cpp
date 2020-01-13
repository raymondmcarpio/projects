#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int times, rolls;
	double count1 = 0;
	double count2 = 0;
	double count3 = 0;
	double count4 = 0;
	double count5 = 0;
	double count6 = 0;

	srand((unsigned int)time(NULL));

	cout << "How many times would you like to roll the dice?" << endl;
	cin >> times;

	while (times < 1){
		cout << "This is an invalid number. \n"
			<< "The number of rolls should be equal to or greater than 1.\n"
			<< "Please enter again." << endl;
		cin >> times;
	}
	cout << endl;

	for (int i = 0; i < times; i++){
		rolls = rand() % 6 + 1;

		if (rolls == 1){
			count1++;
		}
		else if (rolls == 2){
			count2++;
		}
		else if (rolls == 3){
			count3++;
		}
		else if (rolls == 4){
			count4++;
		}
		else if (rolls == 5){
			count5++;
		}
		else{
			count6++;
		}

	}

	cout << "DICE ROLL STATISTICS\n" << endl;
	cout << "# Rolled 	 # Times 	 % Times\n"
		<< "-------- 	 -------- 	 --------" << endl;
	cout << fixed << setprecision(0) << "      " << 1 << " 	" << setw(8) << count1 << " 	" << setw(8) << fixed << setprecision(2) << (count1 / times) * 100 << "%" << endl;
	cout << fixed << setprecision(0) << "      " << 2 << " 	" << setw(8) << count2 << " 	" << setw(8) << fixed << setprecision(2) << (count2 / times) * 100 << "%" << endl;
	cout << fixed << setprecision(0) << "      " << 3 << " 	" << setw(8) << count3 << " 	" << setw(8) << fixed << setprecision(2) << (count3 / times) * 100 << "%" << endl;
	cout << fixed << setprecision(0) << "      " << 4 << " 	" << setw(8) << count4 << " 	" << setw(8) << fixed << setprecision(2) << (count4 / times) * 100 << "%" << endl;
	cout << fixed << setprecision(0) << "      " << 5 << " 	" << setw(8) << count5 << " 	" << setw(8) << fixed << setprecision(2) << (count5 / times) * 100 << "%" << endl;
	cout << fixed << setprecision(0) << "      " << 6 << " 	" << setw(8) << count6 << " 	" << setw(8) << fixed << setprecision(2) << (count6 / times) * 100 << "%" << endl;
	
	system("pause");
	return 0;
}