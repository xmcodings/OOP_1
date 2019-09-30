#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Student.h"
#include "DBMS.h"
#include "input_helper.h"

class UI {
public:

	input_helper input;
	DBMS manager;
	vector<Student> searched_student;
	UI(DBMS studentDB, input_helper helper);

	void go();
	int print_menu();
	void UI_insertion();
	void UI_search();
	void UI_deletion();
	void print_students();
	void UI_edit();

};
