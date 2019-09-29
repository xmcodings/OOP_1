#pragma once
#include <iostream>
#include <string>

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

	bool nameCheck(string name);
	bool idCheck(long id);
	bool ageCheck(int age);
	bool telCheck(string tel);
	bool sameId(long id);
	string getName();
	long getID();
	string getDepartment();
	int getAge();
	string getTelephone();
	bool operator<(const Student& other) const //dbms에서 result에 들어있는 것들 
	{
		return name < other.name;
	}
	//long을 한 이유는 12자리까지 소화해야되서입니다

	

};