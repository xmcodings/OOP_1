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

bool Student::compareName(const Student& a, const Student& b)
{
	return a.name < b.name;
}

bool Student::compareId(const Student& a, const Student& b)
{
	return a.id < b.id;
}

bool Student::compareDept(const Student& a, const Student& b)
{
	return a.department < b.department;
}

bool Student::compareAge(const Student& a, const Student& b)
{
	return a.age < b.age;
}


