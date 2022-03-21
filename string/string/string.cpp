#include <iostream>
#include <fstream> 
#include "str.h"
using namespace std;


int main()
{
	char arr[] = "hello \0";
	char mass[] = "wold\0";
	str a(arr, 7);
	str d(mass, 5);
	str e;
	cout << a;
	e = a + d;
	cout << e;
	return 0;
}