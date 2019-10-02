#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Student.h"
#include "DBMS.h"
#include "Input_Helper.h"

class UI {
private:
	vector<Student> searched_student;
public:
	Input_Helper input;
	DBMS manager;


	UI(DBMS studentDB, Input_Helper helper);
	void go();
	int print_menu();
	void UI_insert();
	void UI_search();
	void UI_delete();
	void print_students();
	void UI_edit();

};
