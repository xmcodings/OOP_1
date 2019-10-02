#include "UI.h"


int main(int argc, char* argv[]) {

	string filename;
	filename = argv[1];
	DBMS studentDB(filename);
	Input_Helper input;
	UI UI(studentDB, input);
	UI.go();
	system("pause");
	return 0;
}
