#pragma once
#include<string>
#include <iomanip>

class input_helper {

public:
	input_helper();
	int insert_int();
	int insert_int_1_to_5();
	int insert_int_1_or_2();
	int insert_int_with_pass();
	int insert_age();

	long insert_long();
	long insert_id();

	std::string insert_string();
	std::string insert_name_dept_tel();

};


