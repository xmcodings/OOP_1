#include "Student.h"

Student::Student(string name, long id,  string department, int age, string tel) {
	this->name = name;
	this->id = id;
	this->age = age;
	this->department = department;
	this->tel = tel;//set �ȸ���� �����ڿ��� ���������
}

Student::Student(string name, long id) {
	this->name = name;
	this->id = id;
	this->age = 0;//���⼭���� �ʱ�ȭ
	this->department = "";
	this->tel = '0';
}//name, id �̿ܿ� �Է� �ȵȰ� ������

bool Student::nameCheck(string name) { // student ���̰� 15 ����....
	if (name.size() <= 15) {
		return true;
	}
	else {
		return false;
	}
} //�ٵ� ����θ� �ϴ� ���� �𸣰���..
bool Student::idCheck(long id) {
	if (100000000 <= id < 1000000000) {
		return true; // id �� 9�ڸ�
	}
	else {
		return false;
	}
}
bool Student::ageCheck(int age) {
	if (0 < age < 1000) {
		return true; // ���̰� 3�ڸ���
	}
	else {
		return false;
	}
}
bool Student::telCheck(string tel) {
	if (tel.length() > 10) {
		return true; // ��ȭ��ȣ
	}
	else {
		return false;
	}
}
bool Student::sameId(long id) {
	//DBMS���� ��ġ �ϼ��ϰ� �̿��ϸ� �ɵ��ѵ� �߸𸣰���
	return true;
}

//set ������� get�ؾ���
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
