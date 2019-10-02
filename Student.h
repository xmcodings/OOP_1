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
	bool operator<(const Student& other) const //dbms���� result�� ����ִ� �͵� 
	{
		
		return name < other.name;
	}

	static bool compareName(const Student& a, const Student& b);
	static bool compareId(const Student& a, const Student& b);
	static bool compareDept(const Student& a, const Student& b);
	static bool compareAge(const Student& a, const Student& b);

	



	//long�� �� ������ 12�ڸ����� ��ȭ�ؾߵǼ��Դϴ�

	

};