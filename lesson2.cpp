#include "lesson2.h"
#include <iostream>
#include <random>
#include <string.h>
#define MAX_ELEMENT_BUFFER 10

//3
void PrintUseOperator() {
	int m = 5;
	std::cout << "before: m=" << m << "\n";
	int* pointM = &m;
	*pointM = 10;
	std::cout << "after *pointM = 10 : m=" << m << "\n";


}
//5
void Swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void PrintAllPermtation(char* str, int start, int end) {

	if (start == end) {
		std::cout << str << "\t";
		return;
	}
	for (int i = start; i <= end; i++) {

		Swap(str + start, str + i);
		PrintAllPermtation(str, start + 1, end);
		Swap(str + start, str + i);

	}

}
//14
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int FindMinIndex(int* arr, int n) {
	if (arr == NULL)
		return-1;
	int min = arr[0];
	int imin = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			imin = i;
		}
	}
	return imin;
}
void SortArray(int* arr, int n) {
	int minIndex;
	if (arr == NULL)
		return;
	for (int i = 0; i < n; i++) {
		minIndex = FindMinIndex(arr, n - i);
		Swap(arr, arr + minIndex);
		arr++;
	}

}
//17
int compare(const void* a, const void* b) {
	return *((int*)b) - *((int*)a);
}
void PrintArraySortReverse(int* arr, int n) {
	qsort(arr, n, sizeof(int), compare);
	std::cout << "the sort array is:\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
}

//תרגיל מרכזי
//1
double GetProB() {

	return (double)rand() / RAND_MAX;
}
//2
int* generateData(int*& inbuf, int& count)
{
	int* oldBuff = inbuf;
	if (count == MAX_ELEMENT_BUFFER)
	{
		inbuf = (int*)malloc(sizeof(int));
		if (inbuf == NULL)
		{
			std::cout << "allocation failed\n";
			exit(1);
		}
		count = 1;
		inbuf[0] = rand() % 9 + 1;
		return oldBuff;
	}
	count += 1;

	inbuf = (int*)realloc(inbuf, sizeof(int) * count);

	if (inbuf == NULL)
	{
		std::cout << "allocation failed\n";
		exit(1);
	}
	inbuf[count - 1] = rand() % 9 + 1;

	return NULL;
}
//3
void processData(int*& outbuf, int& count, int& total)
{
	if (outbuf == NULL)
		return;
	for (int i = 0; i < MAX_ELEMENT_BUFFER; i++)
		total += outbuf[i];
	free(outbuf);

	outbuf = NULL;
}
//4
void simulationProgram() {
	int count = 0;
	int* buff = NULL;
	int* oldBuff = NULL;
	int total = 0;

	std::cout << "start of simulation\n";
	for (int i = 0; i < 32; i++)
	{
		oldBuff = generateData(buff, count);
		if (!oldBuff)
			std::cout << "generate new data: " << buff[count - 1] << "   count: " << count << "\n";
		else
		{
			std::cout << "buffer is full. the buffer sending to processData...\n";
			processData(oldBuff, count, total);
			std::cout << "procces data is finish the total: " << total << "\n";
			std::cout << "generate new data: " << buff[count - 1] << "   count: " << count << "\n";

		}
	}

}
