#include "DBMS.h"
/*
예외처리, 파일입출력, exit() 미작성
*/
DBMS::DBMS()
{
	// loadFile() 사용해서 명령행인자 파일 존재 시 내용 다 viewer객체 안의 dbms에 집어넣고,
	//			  존재하지 않을 시 빈 file 생성.
	string line;
	char str[100], * context; //파일에서 받아오는line char형 변환 하기 위한 str
	

	ifstream myfile("student.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			strcpy_s(str, line.c_str()); // line: string ->  char 변환
			char* tok = strtok_s(str, ",", &context); // 구분자","로 파싱 , context 는 보안으로 백업용
			vector<char*> tok_s; //tok_save : student에 insert하기위한 vector

			while (tok != NULL) { //tok_s 에 데이터 저장
				tok_s.push_back(tok);
				tok = strtok_s(NULL, ",", &context);
			}

			string tok_name = tok_s[0]; // char to string 변환
			string tok_depa = tok_s[2];
			string tok_tel = tok_s[4];
			StudentsData.push_back(Student(tok_name, atol(tok_s[1]), tok_depa, atoi(tok_s[3]), tok_tel)); // atoi : char to int , atol : char to long
		}
		myfile.close();
	}
	else
		cout << "Unable to open file !!";
}


void DBMS::insertion(string name, long id,string dept, int age, string tel)
{
	Student newStd(name, id, dept, age, tel);
	if (StudentsData.size() == 0)
	{
		StudentsData.push_back(newStd);
	}
	for (int i = 0; i < StudentsData.size(); i++) {
		if (id == (StudentsData.at(i).getID())) {
			return;
		}
	}
		StudentsData.push_back(newStd);
}

	/*
	int DBMS::insert_id(long id) {
		for (int i = 0; i < StudentsData.size() - 1; i++) {
			if (id == (StudentsData.at(i).getID())) {
				return 0;
			}
			else return 1;
		}
		return 1;
	}


	int DBMS::insert_tel(long tel)
	{
		stdTel = tel;
		return 1;
	}
	int DBMS::insert_name(string name)
	{
		stdName = name;
		return 1;
	}
	int DBMS::insert_dept(string dept)
	{
		stdDept = dept;
		return 1;
	}
	int DBMS::insert_age(int age)
	{
		stdAge = age;
		return 1;
	}
	*/

	//name. Department


void DBMS::saveFile() {
		string name, id, age, department, tel;

		ofstream myfile("student.txt");
		if (myfile.is_open()) {
			for (int i = 0; i < StudentsData.size(); i++) {
				name = StudentsData[i].getName();
				id = to_string(StudentsData[i].getID());
				department = StudentsData[i].getDepartment();
				age = to_string(StudentsData[i].getAge());
				tel = StudentsData[i].getTelephone();

				string str = name + "," + id + "," + department + "," + age + "," + tel + "\n";
				myfile << str;
			}
			myfile.close();
		}
		else
			cout << "Unable to save !!";
	}

bool DBMS::searchDB(int i, string inputStr)
{
	vector<Student> result;
	if (i == 1)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{
			if (this->StudentsData[i].getName() == inputStr) result.push_back(StudentsData[i]);
		}
	}
	else if (i == 3)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{
			if (this->StudentsData[i].getDepartment() == inputStr) result.push_back(StudentsData[i]);
		}
	}
	else return false;

	//sort result
	sort(result.begin(), result.end());

	//store result in SearchResult
	this->SearchResult = result;

	return true;
}

bool DBMS::searchDB(int i, long inputID)
{
	vector<Student> result;
	if (i == 2)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{
			if (this->StudentsData[i].getID() == inputID) result.push_back(StudentsData[i]);
		}
	}
	else return false;

	//sort result
	sort(result.begin(), result.end());

	//store result in SearchResult
	this->SearchResult = result;

	return true;
}

bool DBMS::searchDB(int i, int inputAge)
{
	vector<Student> result;
	if (i == 2)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{
			if (this->StudentsData[i].getAge() == inputAge) result.push_back(StudentsData[i]);
		}
	}
	else return false;

	//sort result
	sort(result.begin(), result.end());

	//store result in SearchResult
	this->SearchResult = result;

	return true;
}

bool DBMS::searchDB(int i)
{
	vector<Student> result;
	if (i == 5)
	{
		result = this->StudentsData;

		//sort result
		//sort(result.begin(), result.end());

		//store result in SearchResult
		this->SearchResult = result;

		return true;
	}
	else return false;
}

vector<Student> DBMS::getReseult()
{
	return SearchResult;
}

bool DBMS::editDBID(int select, long inputID, long newID) {
	int ageCopy;
	long IDCopy;
	string nameCopy, departmentCopy, telCopy;
	vector<Student>::iterator iter = StudentsData.begin();

	if (select == 2)
	{
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = (*iter).getName();
				ageCopy = (*iter).getAge();
				telCopy = (*iter).getTelephone();
				departmentCopy = (*iter).getDepartment();
				IDCopy = newID;
				Student newStd(nameCopy, newID, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);
				break;
			}
		}
		return true;
	}
	return false;
}

bool DBMS::editDBN(int select, long inputID, string newName) {
	int ageCopy;
	long IDCopy;
	string nameCopy, departmentCopy, telCopy;
	vector<Student>::iterator iter = StudentsData.begin();

	if (1)
	{
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = newName;
				ageCopy = (*iter).getAge();
				telCopy = (*iter).getTelephone();
				departmentCopy = (*iter).getDepartment();
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);
				break;
			}
		}
		return true;
	}
	return false;
}

bool DBMS::editDBA(int select, long inputID, int newAge) {
	int ageCopy;
	long IDCopy;
	string nameCopy, departmentCopy, telCopy;
	vector<Student>::iterator iter = StudentsData.begin();

	if (1)
	{
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = (*iter).getName();
				ageCopy = newAge;
				telCopy = (*iter).getTelephone();
				departmentCopy = (*iter).getDepartment();
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);
				break;
			}
		}
		return true;
	}
	return false;
}

bool DBMS::editDBD(int select, long inputID, string newDepartment) {
	int ageCopy;
	long IDCopy;
	string nameCopy, departmentCopy, telCopy;
	vector<Student>::iterator iter = StudentsData.begin();

	if (1)
	{
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = (*iter).getName();
				ageCopy = (*iter).getAge();
				telCopy = (*iter).getTelephone();
				departmentCopy = newDepartment;
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);
				break;
			}
		}
		return true;
	}
	return false;
}

bool DBMS::editDBT(int select, long inputID, string newTel) {
	int ageCopy;
	long IDCopy;
	string nameCopy, departmentCopy, telCopy;
	vector<Student>::iterator iter = StudentsData.begin();

	if (1)
	{
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = (*iter).getName();
				ageCopy = (*iter).getAge();
				telCopy = newTel;
				departmentCopy = (*iter).getDepartment();
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);
				break;
			}
		}
		return true;
	}
	return false;
}


