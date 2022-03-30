// lesson2-tamar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "lesson2.h"
int main()
{

	double x;
	PrintUseOperator();

	for (int i = 0; i < 10; i++)
	{
		x = GetProB();
		if(x>=0&&x<=1)
		std::cout <<x << "\t";
	}
	simulationProgram();
	char a[] = "abcd";
	PrintAllPermtation(a,0,strlen(a)-1);
	int arr[5] = { 5,4,3,2,1 };
	SortArray(arr,5);
	std::cout << "the sort array is:\n";
	for (int i = 0; i < 5; i++)
		std::cout << arr[i];
	PrintArraySortReverse(arr,5);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
