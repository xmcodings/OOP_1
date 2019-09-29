#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Student.h"
#include "DBMS.h"

using namespace std;

class UI {
public:

	DBMS manager;

	UI(DBMS studentDB);


	void go();
	int print_menu();
	void UI_insertion();
	void UI_searching();
	void UI_deletion();
	void print_error(int);
	void UI_edit();
	void UI_printResult();
};
