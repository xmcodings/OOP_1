#include<iostream>
#include"input_helper.h"
#include<string>
#include<math.h>



using namespace std;

input_helper::input_helper() {};
int input_helper::insert_int() {
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
			cout << setw(35) << "Insert int type >> ";
		}
	}
	return i;
}
int input_helper::insert_int_1_to_5() {
	int a = 0;
	while (1) {
		a = insert_int();
		if (1 <= a && a <= 5)
			break;
		else
			cout << setw(35) << "Insert 1~5 >> ";
	}
	return a;
}
int input_helper::insert_int_1_or_2() {
	int a = 0;
	while (1) {
		a = insert_int();
		if (1 <= a && a <= 2)
			break;
		else
			cout << setw(35) << "Insert 1 or 2 >> ";
	}
	return a;
}
int input_helper::insert_int_with_pass() {
	int i;
	string str;
	while (1) {
		getline(cin, str, '\n');
		if (str.size() == 0)
			return 0;
		try {
			i = stoi(str);
			break;
		}
		catch (const std::invalid_argument) {
			cout << setw(35) << "insert integer >> ";
		}
		catch (const std::out_of_range) {
			cout << setw(35) << "insert integer >> ";
		}
	}
	return i;
}
int input_helper::insert_age() {
	int a = 0;
	while (1) {
		a = insert_int_with_pass();
		if (0 <= a && a <= 999)
			break;
		else
			cout << setw(35) << "Insert 1~999 >> ";
	}
	return a;
}

long input_helper::insert_long() {

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
			cout << setw(35) << "Insert long type >> ";
		}
	}
	return ID;
}
long input_helper::insert_id() {
	long id = 0;
	while (1) {
		id = insert_long();
		float a = float(id) / pow(10, 9);
		if (1 < a && a < 10)
			break;
		else
			cout << setw(35) << "id must be 10 digits >> ";
	}
	return id;
}

string input_helper::insert_string() {
	string str;
	while (1) {
		getline(cin, str, '\n');
		if (str.find(',', 0) == string::npos)
			return str;
		else {
			cout << setw(35) << "remove comma >> ";
		}

	}
}
string input_helper::insert_name_dept_tel() {
	string str;
	while (1) {
		str = insert_string();
		if (str.size() == 0 || str.size() > 20)
			if (str.size() > 20)
				cout << setw(35) << "insert less than 20 >> ";
			else
				cout << setw(35) << "insert again >> ";
		else
			break;
	}
	return str;
}




