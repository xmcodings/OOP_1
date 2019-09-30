#include "UI.h"
#include "input_helper.h"


using namespace std;


UI::UI(DBMS studentDB, input_helper input_helper)
{
	manager = studentDB;
	input = input_helper;
}

void UI::go() {
	int user_celection;
	cout.setf(ios::right);
	while (1) {
		/*************** Menu 띄우기 ****************************************************************/
		user_celection = this->print_menu();
		if (user_celection == 5)
		{
			manager.saveFile();
			break;
		}
		/************** switch로 분할 처리 **********************************************************/
		switch (user_celection) {
		case 1:
			this->UI_insertion();
			break;
		case 2:
			this->UI_search();
			break;
		case 3:
			this->UI_deletion();
			break;
		case 4:
			this->UI_edit();
			break;
		default:
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int UI::print_menu() {
	int i;
	system("cls");
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << "          ---------- Menu ---------            \n\n\n";
	cout << "                 1. Insert        \n\n";
	cout << "                 2. Search        \n\n";
	cout << "                 3. Delete        \n\n";
	cout << "                 4. Edit		   \n\n";
	cout << "                 5. Terminate     \n\n";
	cout << "          -------------------------            \n\n\n";
	cout << setw(25) << "Choose Number >> ";
	cin >> i;
	return i;
};
void UI::UI_insertion() {
	string name;
	string department;
	string tel;
	long ID;
	int age;

	system("cls");
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << "        ---------- Insertion ----------            \n\n\n";
	cout << "           1. Student Name       : ";
	name = input.insert_name_dept_tel();
	cout << "\n\n           2. Student ID         : ";
	ID = input.insert_id();
	cout << "\n\n           3. Student Department : ";
	department = input.insert_name_dept_tel();
	cout << "\n\n           4. Student Age        : ";
	age = input.insert_age();
	cout << "\n\n           5. Student Tel.       : ";
	tel = input.insert_name_dept_tel();
	cout << "\n        -------------------------------            \n\n";

	cout.setf(ios::left, ios::adjustfield);
	cout << string(80, '-') << endl;
	cout << setw(20) << "NAME" << setw(14) << "ID" << setw(20) << "DEPARTMENT" << setw(5) << "AGE" << setw(20) << "TELEPHONE" << endl;
	cout << setw(20) << name << setw(14) << ID << setw(20) << department << setw(5) << age << setw(15) << tel << endl;
	cout << string(80, '-') << endl;
	cout.setf(ios::right, ios::adjustfield);
	int check = 0;
	cout << "      Do you want to insert? (1=Yes, 2=No) >> ";
	check = input.insert_int_1_or_2();
	if (check == 1) {
		check = manager.insertion(name, ID, department, age, tel);
		if (check == false) {
			cout << "     Insertion failed. there exists same ID..Press Enter to back to menu" << endl;
		}
		else {
			cout << "    Insertion complete. Press Enter to back to menu " << endl;
		}
	}
	else {
		cout << "    Insertion denied. Press Enter to back to menu " << endl;
	}
};
void UI::UI_search() {
	int i;
	string name;
	string department;
	long ID;
	int age;
	system("cls");
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << "          ---------- search by ----------            \n\n\n";
	cout << "                    1. Name \n\n";
	cout << "                    2. ID	 \n\n";
	cout << "                    3. Department	\n\n";
	cout << "                    4. Age	\n\n";
	cout << "                    5. List all \n\n";
	cout << "               Choose Number >> ";
	i = input.insert_int_1_to_5();
	cout << "          -------------------------------            \n\n\n";
	switch (i) {
	case 1:
		cout << setw(25) << " Name >> ";
		name = input.insert_name_dept_tel();
		manager.searchDB(i, name);
		break;
	case 2:
		cout << setw(25) << "ID >> ";
		ID = input.insert_id();
		manager.searchDB(i, ID);
		break;
	case 3:
		cout << setw(25) << "department >> ";
		department = input.insert_string();
		manager.searchDB(i, department);
		break;
	case 4:
		cout << setw(25) << "Age >> ";
		age = input.insert_age();
		manager.searchDB(i, age);
		break;

	case 5:
		manager.searchDB(i);



		break;
	}
	int sortAgain = 0;
	int count = 0;
	do
	{
		system("cls");
		
		cout << manager.sortBy(count % 4) << endl;
		this->searched_student = manager.getReseult();
		this->print_students();
		cout << "Press 1 to sort differnetly, 2 to exit" << endl;
		sortAgain = input.insert_int_1_or_2();
		count = count + 1;

	} while (sortAgain == 1);
	
};
void UI::UI_deletion() {
	long id;
	system("cls");
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << "          ---------- Deletion ----------            \n\n\n";
	cout << "\n\n" << setw(25) << "Student ID : ";
	id = input.insert_id();

	if (!(manager.checkID(id)))
	{
		cout << " There is no such an ID. Press Enter to back to menu  >> \n";
		return;
	}
	this->searched_student = manager.getReseult();
	this->print_students();

	int check = 0;
	cout << "      Do you want to delete? (1=Yes, 2=No) >> ";
	check = input.insert_int_1_or_2();
	if (check == 1) {
		check = manager.deletion(id);
		cout << "    deletion complete. Press Enter to back to menu " << endl;
	}
	else {
		cout << "    deletion denied. Press Enter to back to menu " << endl;
	}
}
void UI::UI_edit() {
	int selection, newAge;
	string newName, newDepartment, newTel;
	long ID;
	long newID;
	system("cls");
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << setw(35) << "Insert student's ID >> ";
	ID = input.insert_id();
	
	if (!(manager.checkID(ID)))
	{
		cout << " no ID, Press Enter to back to menu >> \n";
		return;
	}

	this->searched_student = manager.getReseult();
	this->print_students();

	cout << "\n          ---------- Edit ----------            \n\n\n";
	cout << "                    1. Name \n\n";
	cout << "                    2. Department	 \n\n";
	cout << "                    3. Age	\n\n";
	cout << "                    4. Telephone	\n\n";
	cout << "                    5. Back to menu \n\n";
	cout << "               Choose Number >> ";
	selection = input.insert_int_1_to_5();
	if (selection != 5)
		cout << "\nChange to : ";
	switch (selection) {
	case 1: //Name
		newName = input.insert_name_dept_tel();
		manager.editDBN(selection, ID, newName);
		break;
	case 2: //Department
		newDepartment = input.insert_name_dept_tel();
		manager.editDBD(selection, ID, newDepartment);
		break;
	case 3: //Age
		newAge = input.insert_age();
		manager.editDBA(selection, ID, newAge);
		break;
	case 4: //Tel
		newTel = input.insert_name_dept_tel();
		manager.editDBT(selection, ID, newTel);
		break;
	case 5:
		break;
	}
	cout << "\n             Press Enter to back to menu >> ";
}

void UI::print_students() {
	cout.setf(ios::left, ios::adjustfield);
	cout << string(80, '-') << endl;
	cout << setw(20) << "NAME";
	cout << setw(14) << "ID";
	cout << setw(20) << "DEPARTMENT";
	cout << setw(5) << "AGE";
	cout << setw(20) << "TELEPHONE" << endl;
	cout << string(80, '-') << endl;
	for (int i = 0; i < this->searched_student.size(); i++)
	{
		Student s = this->searched_student[i];
		cout << setw(20) << s.getName();
		cout << setw(14) << s.getID();
		cout << setw(20) << s.getDepartment();
		cout << setw(5) << s.getAge();
		cout << setw(15) << s.getTelephone() << endl;
	}
	cout << setw(80) << endl;
	cout.setf(ios::right, ios::adjustfield);
}

