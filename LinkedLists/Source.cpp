#include <iostream>
#include <vector>
#include "tForwardList.h"
#include "Sort.h"

int main()
{
	tList<int> appleBundles; //Start List

	for (int i = 0; i < 6; ++i) //Push Front
		appleBundles.push_front(i);

	tList<int> copyList(appleBundles); // Copy: Start List
	copyList.push_front(5); // Copy: Push Front

	copyList = appleBundles; // ==operator

	appleBundles.resize(3); // resize min
	appleBundles.resize(6); // resize max

	for (int i = 0; i < 6; i++) // Pop Front
		appleBundles.pop_front();

	for (int i = 0; i < 6; ++i)
		appleBundles.push_back(i);

	for (int i = 0; i < 6; i++) // Pop Back
		appleBundles.pop_back();

	for (int i = 0; i < 6; ++i)
		appleBundles.push_front(i);

	int x = appleBundles.front(); //Front()
	int y = appleBundles.back(); //Back()
	bool b = appleBundles.empty(); // Empty()
	const int z = appleBundles.front(); //const Front()
	const int w = appleBundles.back(); // const Back()

	appleBundles.remove(3); // Remove
	appleBundles.clear(); // Clear

	//----------------------------------------copyList

	for (int i = 0; i < 6; ++i) // Copy: Push Front
		copyList.push_front(i);

	copyList.resize(3); // Copy: resize min
	copyList.resize(6); // Copy: resize max
	copyList.pop_front(); // Copy: Pop Front
	copyList.pop_back(); // Copy: Pop Back

	int u = copyList.front(); // Copy: Front()
	int i = copyList.back(); // Copy: Back()
	bool o = copyList.empty(); // Copy: Empty()
	const int p = copyList.front(); // Copy: Front()
	const int l = copyList.back(); // Copy: Back()

	copyList.remove(0); // Copy: Remove 
	copyList.clear(); // Copy: Clear

	//---------------------------------------------------------------bubble-sort

	Sort srt;

	std::vector<int> sortTest;

	for (int i = 5; i > 0; i--)
	{
		sortTest.push_back(i);
		sortTest.push_back(i + 1);
	}

	srt.bubbleSort(sortTest); // BubbleSort

	return 0;
}