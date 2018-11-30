//#include "List.h"
//#include "Dictionary.h"
#include "Windows.h"
#include "stdio.h"


int main() {
	float f = 5286348.0f;
	int * pInt = (int*)(void*)&f;
	printf("%u\n", *pInt);
	system("pause");
}
