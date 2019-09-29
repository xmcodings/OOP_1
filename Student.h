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
	bool operator<(const Student& other) const //dbms���� result�� ����ִ� �͵� 
	{
		return name < other.name;
	}
	//long�� �� ������ 12�ڸ����� ��ȭ�ؾߵǼ��Դϴ�

	

};