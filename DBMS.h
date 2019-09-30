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
	void loadFile(string filename);
	
	//private �ȿ� �ְ� DBMS �����ڸ� ���� ���߿� DBMS ������ �� ��ü������..
	vector<Student> SearchResult;

	string filename;



public:
	DBMS(string filename);
	DBMS();
	bool insertion(string name, long id, string dept, int age, string tel);
	
	// searchDB: ui���� bool�� ���� -> ���̸� ui���� SearchResult ���, �����̸� ������Ȳ ǥ��
	bool searchDB(int i, string inputStr);
	bool searchDB(int i, int inputAge);
	bool searchDB(int i, long inputID);
	bool searchDB(int i);
	vector<Student> getReseult();
	void saveFile();
	bool checkID(long id);
	string sortBy(int sortby);
	
	
	bool editDBID(int select, long ID, long newID);
	bool editDBN(int select, long ID, string newName);
	bool editDBA(int select, long ID, int newAge);
	bool editDBD(int select, long ID, string newDepartment);
	bool editDBT(int select, long ID, string newTel);
	bool deletion(long StudentID);
};
