#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student {
private:
	int age;
	long id;
	string tel;
	string name, department;
public:
	Student(string name, long id, string department, int age, string tel);
	Student(string name, long id);

	string getName();
	long getID();
	string getDepartment();
	int getAge();
	string getTelephone();
	bool operator<(const Student& other) const //dbms에서 result에 들어있는 것들 
	{
		
		return name < other.name;
	}

	static bool compareName(const Student& a, const Student& b);
	static bool compareId(const Student& a, const Student& b);
	static bool compareDept(const Student& a, const Student& b);
	static bool compareAge(const Student& a, const Student& b);

	



	//long을 한 이유는 12자리까지 소화해야되서입니다

	

};