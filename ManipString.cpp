#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string toInverse(string);
string reverseString(string);
string toUpperCase(string);
void countWords(string);
void countConsonant(string);
string newString(string);
void printString(string);

int main()
{
	string message;
	char selection;
	cout << "Please enter a word, a sentence, or a string of numbers.\n" << endl;
	getline(cin, message);

	do {
		cout << "USE THIS MENU TO MANIPULATE YOUR STRING\n"
			<< "---------------------------------------\n"
			<< "1) Inverse String\n"
			<< "2) Reverse String\n"
			<< "3) To Uppercase\n"
			<< "4) Count Number Words\n"
			<< "5) Count Consonants\n"
			<< "6) Enter a Different String\n"
			<< "7) Print the string\n"
			<< "Q) Quit\n" << endl;
		cin >> selection;
		cin.ignore();

		if (selection == '1') {
			message = toInverse(message);
		}
		else if (selection == '2') {
			message = reverseString(message);
		}
		else if (selection == '3') {
			message = toUpperCase(message);
		}
		else if (selection == '4') {
			countWords(message);
		}
		else if (selection == '5') {
			countConsonant(message);
		}
		else if (selection == '6') {
			message = newString(message);
		}
		else if (selection == '7') {
			printString(message);
		}
		else if((selection != 'Q' && selection != 'q') && (selection < '1' || selection > '7')) {
			cout << "Invalid selection. Please try again.\n" << endl;
		}

	} while (selection != 'Q' && selection != 'q');
	cout << "You have chosen to quit the program. Thank you!" << endl;

	system("pause");
	return 0;
}

string toInverse(string message) {

	string mess;
	for (int i = 0; i < message.length(); ++i) {
		if (isupper(message[i])) {
			message[i] = char(tolower(message[i]));
		}
		else {
			message[i] = char(toupper(message[i]));
		}
	}
	for (int i = 0; i < message.length(); ++i) {
		mess = mess + message[i];
	}
	return mess;
}
string reverseString(string message) {

	string mess;
	for (int i = message.length()-1; i >= 0; --i) {
		mess = mess + message[i];
	}
	return mess;
}
string toUpperCase(string message) {
	string mess;
	for (int i = 0; i < message.length(); ++i) {
		if (!isupper(message[i])) {
			message[i] = char(toupper(message[i]));
		}
	}
	for (int i = 0; i < message.length(); ++i) {
		mess = mess + message[i];
	}
	return mess;
}
void countWords(string message) {
	int count = 0;
	for (int i = 0; i < message.length(); ++i) {
		if (message[i] == ' ' && message[i - 1] != ' ') {
			count++;
		}
	}
	cout << "The string \"" << message << "\" has " << count + 1 << " word(s)\n" << endl;
	
}
void countConsonant(string message) {
	int consonant = 0;
	for (int i = 0; i < message.length(); ++i) {
		if (message[i] != 'A' && message[i] != 'a' &&
			message[i] != 'E' && message[i] != 'e' &&
			message[i] != 'I' && message[i] != 'i' &&
			message[i] != 'O' && message[i] != 'o' &&
			message[i] != 'U' && message[i] != 'u' &&
			message[i] != '!' && message[i] != ' ') {
			consonant++;
		}
	}
	cout << "The number of consonants in the string is " << consonant << ".\n" << endl;
}
string newString(string message) {
	string mess;
	cout << "Enter a different string : \n" << endl;
	getline(cin, message);
	mess = message;

	return mess;
}

void printString(string message) {
	cout << "The current string is: " << message << endl << endl;
}

