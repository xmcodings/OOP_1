#include "Student.h"

Student::Student(string name, long id,  string department, int age, string tel) {
	this->name = name;
	this->id = id;
	this->age = age;
	this->department = department;
	this->tel = tel;//set 안만들고 생성자에서 지정해줬다
}

Student::Student(string name, long id) {
	this->name = name;
	this->id = id;
	this->age = 0;//여기서부터 초기화
	this->department = "";
	this->tel = '0';
}//name, id 이외에 입력 안된거 있을때

bool Student::nameCheck(string name) { // student 길이가 15 이하....
	if (name.size() <= 15) {
		return true;
	}
	else {
		return false;
	}
} //근데 영어로만 하는 법을 모르겠음..
bool Student::idCheck(long id) {
	if (100000000 <= id < 1000000000) {
		return true; // id 가 9자리
	}
	else {
		return false;
	}
}
bool Student::ageCheck(int age) {
	if (0 < age < 1000) {
		return true; // 나이가 3자리수
	}
	else {
		return false;
	}
}
bool Student::telCheck(string tel) {
	if (tel.length() > 10) {
		return true; // 전화번호
	}
	else {
		return false;
	}
}
bool Student::sameId(long id) {
	//DBMS에서 서치 완성하고 이용하면 될듯한데 잘모르겠음
	return true;
}

//set 해줬던걸 get해야지
string Student::getName() {
	return this->name;
}
long Student::getID() {
	return this->id;
}
string Student::getDepartment() {
	return this->department;
}
int Student::getAge() {
	return this->age;
}
string Student::getTelephone() {
	return this->tel;
}
