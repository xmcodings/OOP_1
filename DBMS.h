#pragma once
#include <iostream>
#include <fstream>
#include <vector> //��̸���Ʈ C++����
#include <algorithm> //std::sort() ����� ����
#include "Student.h"
using namespace std;

class DBMS {
private:
	vector<Student> StudentsData;//�Ľ��ؼ� ���� ������ɵ�..
	//���߿� exit ������ �� ��ü������
	bool loadFile();//private �ȿ� �ְ� DBMS �����ڸ� ���� ���߿� DBMS ������ �� ��ü������..
	bool fileExist(); 
	vector<Student> SearchResult;
	vector<Student>::iterator Iter;
	string stdName;
	int stdAge;
	string stdDept;
	string stdTel;
	long stdId;



public:
	DBMS();
	void insertion(string name, long id, string dept, int age, string tel);
	
	// searchDB: ui���� bool�� ���� -> ���̸� ui���� SearchResult ���, �����̸� ������Ȳ ǥ��
	bool searchDB(int i, string inputStr);
	bool searchDB(int i, int inputAge);
	bool searchDB(int i, long inputID);
	bool searchDB(int i);
	vector<Student> getReseult();
	void saveFile();
	bool editDBID(int select, long ID, long newID);
	bool editDBN(int select, long ID, string newName);
	bool editDBA(int select, long ID, int newAge);
	bool editDBD(int select, long ID, string newDepartment);
	bool editDBT(int select, long ID, string newTel);
};
