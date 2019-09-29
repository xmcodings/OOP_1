#pragma once
#include <iostream>
#include <fstream>
#include <vector> //어레이리스트 C++에서
#include <algorithm> //std::sort() 사용을 위해
#include "Student.h"
using namespace std;

class DBMS {
private:
	vector<Student> StudentsData;//파싱해서 여기 넣으면될듯..
	//나중에 exit 구현할 때 구체적으로
	bool loadFile();//private 안에 넣고 DBMS 생성자를 만들어서 나중에 DBMS 구현할 때 구체적으로..
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
	
	// searchDB: ui에서 bool값 받음 -> 참이면 ui에서 SearchResult 출력, 거짓이면 에러상황 표시
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
