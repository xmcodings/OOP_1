#include "type_check.h"
#include<iostream>
#include<string>

using namespace std;

int check_insert_int() {
	int i;
	while (1) {
		cin >> i;
		if (!cin.fail()) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "               Insert int type >> ";
		}
	}
	return i;
}

long check_insert_long() {

	long ID;
	while (1) {
		cin >> ID;
		if (!cin.fail()) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "               Insert long type >> ";
		}
	}
	return ID;
}

string check_insert_string() {
	string str;
	getline(cin, str, '\n');
	return str;
}
int check_int_1_to_5() {
	int a = 0;
	while (1) {
		a = check_insert_int();
		if (1 <= a && a <= 5)
			break;
		else
			cout << "               Insert 1~5 >> ";
	}
	return a;
}