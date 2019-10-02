#include "DBMS.h"
/*
예외처리, 파일입출력, exit() 미작성
*/
DBMS::DBMS(string filename)
{
	// loadFile() 사용해서 명령행인자 파일 존재 시 내용 다 viewer객체 안의 dbms에 집어넣고,
	//			  존재하지 않을 시 빈 file 생성.
	this->filename = filename;
	loadFile(filename);
}

DBMS::DBMS()
{
}

bool DBMS::insertDB(string name, long id, string dept, int age, string tel)
{
	Student newStd(name, id, dept, age, tel);
	if (StudentsData.size() == 0)
	{
		StudentsData.push_back(newStd);
		return true;
	}
	for (int i = 0; i < StudentsData.size(); i++) {
		if (id == (StudentsData.at(i).getID())) {
			return false;
		}
	}
	StudentsData.push_back(newStd);
	
	//파일로그에 데이터 저장
	string filelog = getTime() + " / insert / " + to_string(id) + "\n";
	Filelog.push_back(filelog);
	return true;
}

bool DBMS::searchDB(int i, string inputStr)
{
	vector<Student> result;
	string input_lcase;
	string search_lcase;
	input_lcase = inputStr;
	transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
	if (i == 1)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{	
			search_lcase = this->StudentsData[i].getName();
			transform(search_lcase.begin(), search_lcase.end(), search_lcase.begin(), ::tolower);
			if (search_lcase == input_lcase) result.push_back(StudentsData[i]);
		}
	}
	else if (i == 3)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{
			search_lcase = this->StudentsData[i].getDepartment();
			transform(search_lcase.begin(), search_lcase.end(), search_lcase.begin(), ::tolower);
			if (search_lcase == input_lcase) result.push_back(StudentsData[i]);
		}
	}
	else return false;

	//sort result
	sort(result.begin(), result.end(), Student::compareName);

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
	sort(result.begin(), result.end(), Student::compareName);

	//store result in SearchResult
	this->SearchResult = result;

	return true;
}

bool DBMS::searchDB(int i, int inputAge)
{
	vector<Student> result;
	if (i == 4)
	{
		for (unsigned int i = 0; i < this->StudentsData.size(); i++)
		{
			if (this->StudentsData[i].getAge() == inputAge) result.push_back(StudentsData[i]);
		}
	}
	else return false;

	//sort result
	sort(result.begin(), result.end(), Student::compareName);

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
		sort(result.begin(), result.end(), Student::compareName);

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

void DBMS::editDB(int select, long inputID, string newString) {

	int ageCopy;
	long IDCopy;
	string nameCopy, departmentCopy, telCopy;
	vector<Student>::iterator iter = StudentsData.begin();


	if (select == 1) {
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				//filelog에 저장할 이름
				string name_old = (*iter).getName();

				nameCopy = newString;
				ageCopy = (*iter).getAge();
				telCopy = (*iter).getTelephone();
				departmentCopy = (*iter).getDepartment();
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);

				//file log 생성
				string filelog = getTime() + " / edit-name / " + to_string(IDCopy) + " / " + name_old + " / " + nameCopy + "\n";
				Filelog.push_back(filelog);
				break;
			}
		}
	}

	else if (select == 2) {
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = (*iter).getName();
				ageCopy = (*iter).getAge();
				telCopy = (*iter).getTelephone();
				//filelog 저장용 department
				string department_old = (*iter).getDepartment();

				departmentCopy = newString;
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);

				//file log 생성
				string filelog = getTime() + " / edit-department / " + to_string(IDCopy) + " / " + department_old + " / " + departmentCopy + "\n";
				Filelog.push_back(filelog);
				break;
			}
		}
	}
	else if (select == 4) {
		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {

				nameCopy = (*iter).getName();
				ageCopy = (*iter).getAge();
				//filelog 저장용 telephone
				string tel_old = (*iter).getTelephone();
				telCopy = newString;
				departmentCopy = (*iter).getDepartment();
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);

				//file log 생성
				string filelog = getTime() + " / edit-telephone / " + to_string(IDCopy) + " / " + tel_old + " / " + telCopy + "\n";
				Filelog.push_back(filelog);
				break;
			}
		}
	}
}

void DBMS::editDB(int select, long inputID, int newAge) {

	if (select == 3) {

		int ageCopy;
		long IDCopy;
		string nameCopy, departmentCopy, telCopy;
		vector<Student>::iterator iter = StudentsData.begin();

		for (iter; iter != StudentsData.end(); iter++)
		{
			if ((*iter).getID() == inputID) {
				nameCopy = (*iter).getName();
				//filelog 저장용 age
				int age_old = (*iter).getAge();

				ageCopy = newAge;
				telCopy = (*iter).getTelephone();
				departmentCopy = (*iter).getDepartment();
				IDCopy = (*iter).getID();
				Student newStd(nameCopy, IDCopy, departmentCopy, ageCopy, telCopy);
				StudentsData.erase(iter);
				StudentsData.push_back(newStd);

				//file log 생성
				string filelog = getTime() + " / edit-age / " + to_string(IDCopy) + " / " + to_string(age_old) + " / " + to_string(ageCopy) + "\n";
				Filelog.push_back(filelog);
				break;
			}
		}

	}
}

bool DBMS::deleteDB(long StudentID) {
	vector<Student>::iterator Iter; //vector 포인터
	Iter = StudentsData.begin();
	for (int i = 0; i < StudentsData.size(); i++) {
		if (StudentsData[i].getID() == StudentID) {
			//filelog 추가
			string filelog = getTime() + " / delete / " + to_string(StudentsData.at(i).getID()) + "\n";
			Filelog.push_back(filelog);
			//데이터 삭제
			StudentsData.erase(Iter);
			return true;
		}
		Iter++;
	}
	return false;
}

void DBMS::loadFile(string filename)
{
	string line;
	char str[100], * context; //파일에서 받아오는line char형 변환 하기 위한 str


	ifstream myfile(filename);
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
	else {
		// 파일없을때 아무일도 없음
	}
		
}

void DBMS::saveFile() {
	string name, id, age, department, tel;

	ofstream myfile(filename);
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

void DBMS::saveLog() {
	fstream myfile("filelog.txt");
	if (myfile.is_open()) {
		myfile.seekg(0, ios::end);
		for (int i = 0; i < Filelog.size(); i++) {
			myfile << Filelog.at(i);
		}
		myfile.close();
	}
	// 파일 없을경우 파일 생성
	else {
		ofstream myfile2("filelog.txt");
		if (myfile2.is_open()) {
			myfile2 << "작성일자 / 타입 / 학번 / 이전 내용 / 수정 후 내용"<<endl;
			for (int i = 0; i < Filelog.size(); i++) {
				myfile2 << Filelog.at(i);
			}
			myfile2.close();
		}
	}
}
bool DBMS::checkID(long id){
	if (StudentsData.size() == 0)
	{
		return false;
	}
	for (int i = 0; i < StudentsData.size(); i++) {
		if (id == (StudentsData.at(i).getID())) {
			searchDB(2, id);
			return true;
		}
	}
	return false;
}

string DBMS::sortBy(int sortby)
{
	switch (sortby)
	{
	case 0:
		sort(SearchResult.begin(), SearchResult.end(), Student::compareName);
		return "<Sorted by name>";
		break;

	case 1:
		sort(SearchResult.begin(), SearchResult.end(), Student::compareId);
		return "<Sorted by ID>";
		break;
	case 2: 
		sort(SearchResult.begin(), SearchResult.end(), Student::compareDept);
		return "<Sorted by department>";
		break;
	case 3:
		sort(SearchResult.begin(), SearchResult.end(), Student::compareAge);
		return "<Sorted by age>";
		break;
	default:
		return "error";
		break;
	}
}

// 현재 시간 string 반환
string DBMS::getTime() {
	time_t curr_time;

	// 시간 표시를 위한 구조체를 선언합니다.
	struct tm curr_tm;

	// time 함수는 1970년 1월 1일 이후 몇초가 지났는지를 계산합니다. NULL을 인자로 사용합니다.
	curr_time = time(NULL);

	// 지역 시간을 기준으로 변환 및 출력 편의를 위하여 tm 구조체에 저장합니다.(포맷팅)
	localtime_s(&curr_tm, &curr_time);

	string year = to_string(curr_tm.tm_year + 1900) + "년 ";
	string month = to_string(curr_tm.tm_mon + 1) + "일 ";
	string day = to_string(curr_tm.tm_mday) + "일 ";
	string hour = to_string(curr_tm.tm_hour) + "시 ";
	string minute = to_string(curr_tm.tm_min) + "분 ";

	string time = year + month + day + hour + minute;

	return time;
} 

