#include <iostream>
#include "Array.h"
using namespace std;

int main(int argc, char** argv)
{
	srand(time(0));

	Array<int> arr1(5);
	arr1.FillArray();
	cout << "Array #1: ";
	arr1.PrintArray();

	Array<int> arr2(5);
	arr2.FillArray();
	cout << "Array #2: ";
	arr2.PrintArray();

	cout << "--- Operations ---" << endl;
	Array<int> rez = arr1 + arr2;
	cout << "Sum: ";
	rez.PrintArray();
	cout << endl;

	system("pause");
}
