#pragma once
#include <iostream>
#include <fstream>
#include <vector> //어레이리스트 C++에서
#include <algorithm> //std::sort() 사용을 위해
#include "Student.h"
#include <time.h>
using namespace std;

class DBMS {
private:
	vector<Student> StudentsData;//파싱해서 여기 넣으면될듯..
	//나중에 exit 구현할 때 구체적으로
	void loadFile(string filename);
	
	//private 안에 넣고 DBMS 생성자를 만들어서 나중에 DBMS 구현할 때 구체적으로..
	vector<Student> SearchResult;

	vector<string> Filelog;

	string filename;



public:
	DBMS(string filename);
	DBMS();
	bool insertDB(string name, long id, string dept, int age, string tel);
	
	// searchDB: ui에서 bool값 받음 -> 참이면 ui에서 SearchResult 출력, 거짓이면 에러상황 표시
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
