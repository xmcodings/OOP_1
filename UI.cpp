#include "UI.h"
#include "Student.h"
#include "type_check.h"


UI::UI(DBMS studentDB)
{
	manager = studentDB;
}

void UI::go() {
	int user_celection;
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
			this->UI_searching();
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
	cout << "                 4. Edit          \n\n";
	cout << "                 5. Terminate     \n\n";
	cout << "          -------------------------            \n\n\n";
	cout << "          Choose Number >> ";
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

	// insert name
	cout << "           1. Student Name       : ";
	name = check_insert_string();
	// insert ID
	cout << "\n\n           2. Student ID         : ";
	ID = check_insert_long();
	// insert Department
	cout << "\n\n           3. Student Department : ";
	department = check_insert_string();
	// insert Age
	cout << "\n\n           4. Student Age        : ";
	age = check_insert_int();
	// insert tel
	cout << "\n\n           5. Student Tel.       : ";
	tel = check_insert_string();
	

	cout << "\n        -------------------------------            \n\n";
	cout << "    Insertion complete. Press Enter to back to menu ";

	// int a = DBMS.insertion(name, string) (0 이면 학번 중복)
	manager.insertion(name, ID, department, age, tel);
};
void UI::UI_searching() {
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
	i = check_int_1_to_5();
	cout << "          -------------------------------            \n\n\n";
	switch (i) {
	case 1:
		cout << "                    Name >>";
		name = check_insert_string();
		manager.searchDB(i, name);
		UI_printResult();
		break;
	case 2:
		cout << "                    ID >>";
		ID = check_insert_long();
		manager.searchDB(i, ID);
		UI_printResult();
		break;
	case 3:
		cout << "                    department >>";
		department = check_insert_string();
		manager.searchDB(i, department);
		UI_printResult();
		break;
	case 4:
		cout << "                    Age >>";
		age = check_insert_int();
		manager.searchDB(i, age);
		UI_printResult();
		break;

	case 5:
		// DBMS.search_all() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (10/ 11)!!!!!!!!!!!!!!!!!!!
		manager.searchDB(i);
		vector<Student> stds = manager.getReseult();
		system("cls");
		for (int i = 0; i < stds.size(); i++)
		{
			Student s = stds[i];
			cout << s.getName() << s.getID() << s.getDepartment() << s.getAge() << s.getTelephone() << endl;

		}

		break;

	}

};
void UI::UI_deletion() {
	long id;
	system("cls");
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << "          ---------- Deletion ----------            \n\n\n";
	cout << "\n\n               Student ID : ";
	id = check_insert_long();

	// manager.deletion(long ID)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (11 /11) !!!!!!!!!!!!!!!!!!!

};


void UI::print_error(int error_num) {

};

void UI::UI_edit() {
	int selection, newAge;
	string newName, newDepartment, newTel;
	long ID;
	long newID;
	system("cls");
	cout << "\n ======== Student Management System ========\n\n\n";
	cout << "          ---------- Edit ----------            \n\n\n";
	cout << "1.name\n";
	cout << "2.ID\n";
	cout << "3.Department\n";
	cout << "4.Age\n";
	cout << "5.Tel\n\n\n\n";
	cout << "변경할 내용을 고르세요\n";
	cin >> selection;

	switch (selection) {
	case 1:
		cout << " ID검색 >>";
		cin >> ID;
		cout << "Change to:";
		cin >> newName;
		manager.editDBN(selection, ID, newName);
		break;
	case 2:
		cout << " ID검색 >>";
		cin >> ID;
		cout << "Change to:";
		cin >> newID;
		manager.editDBID(selection, ID, newID);
		break;
	case 3:
		cout << " ID검색 >>";
		cin >> ID;
		cout << "Change to:";
		cin >> newDepartment;
		manager.editDBD(selection, ID, newDepartment);
		break;
	case 4:
		cout << "ID검색";
		cin >> ID;
		cout << "Change to:";
		cin >> newAge;
		manager.editDBA(selection, ID, newAge);
		break;
	case 5:
		cout << "ID검색";
		cin >> ID;
		cout << "Change to:";
		cin >> newTel;
		manager.editDBT(selection, ID, newTel);
		break;
	}
}

void UI::UI_printResult()
{
	vector<Student> stds = manager.getReseult();
	system("cls");
	for (int i = 0; i < stds.size(); i++)
	{
		Student s = stds[i];
		cout << s.getName() << s.getID() << s.getDepartment() << s.getAge() << s.getTelephone() << endl;

	}
}