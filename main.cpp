#include "UI.h"


int main(void) {

	DBMS studentDB;
	UI UI(studentDB);
	UI.go();
	system("pause");
	return 0;
}
