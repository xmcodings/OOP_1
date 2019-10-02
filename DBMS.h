#pragma once
#include <iostream>
#include <fstream>
#include <vector> //��̸���Ʈ C++����
#include <algorithm> //std::sort() ����� ����
#include "Student.h"
#include <time.h>
using namespace std;

class DBMS {
private:
	vector<Student> StudentsData;//�Ľ��ؼ� ���� ������ɵ�..
	//���߿� exit ������ �� ��ü������
	void loadFile(string filename);
	
	//private �ȿ� �ְ� DBMS �����ڸ� ���� ���߿� DBMS ������ �� ��ü������..
	vector<Student> SearchResult;

	vector<string> Filelog;

	string filename;



public:
	DBMS(string filename);
	DBMS();
	bool insertDB(string name, long id, string dept, int age, string tel);
	
	// searchDB: ui���� bool�� ���� -> ���̸� ui���� SearchResult ���, �����̸� ������Ȳ ǥ��
	bool searchDB(int i, string inputStr);
	bool searchDB(int i, int inputAge);
	bool searchDB(int i, long inputID);
	bool searchDB(int i);
	vector<Student> getReseult();
	void saveFile();
	void saveLog();
	bool checkID(long id);
	string sortBy(int sortby);
	
	void editDB(int select, long inputID, string newString);
	void editDB(int select, long inputID, int newAge);

	bool deleteDB(long StudentID);

	string getTime();
};
