#include <iostream>
#include <vector>
#include "tForwardList.h"
#include "Sort.h"

int main()
{
	tList<int> appleBundles;

	for (int i = 0; i < 6; ++i)
		appleBundles.push_front(i);

	tList<int> copyList(appleBundles);
	copyList.push_front(5);

	copyList = appleBundles;

	appleBundles.resize(3);
	appleBundles.resize(14);
	appleBundles.pop_front();
	appleBundles.pop_back();

	int x = appleBundles.front();
	int y = appleBundles.back();
	bool b = appleBundles.empty();
	const int z = appleBundles.front();
	const int w = appleBundles.back();

	appleBundles.remove(0);
	appleBundles.clear();

	//----------------------------------------copyList

	for (int i = 0; i < 6; ++i)
		copyList.push_front(i);

	copyList.resize(3);
	copyList.resize(14);
	copyList.pop_front();
	copyList.pop_back();

	int u = copyList.front();
	int i = copyList.back();
	bool o = copyList.empty();
	const int p = copyList.front();
	const int l = copyList.back();

	copyList.remove(0);
	copyList.clear();

	//---------------------------------------------------------------bubble-sort

	Sort srt;

	std::vector<int> sortTest;

	for (int i = 5; i > 0; i--)
		sortTest.push_back(i);

	srt.bubbleSort(sortTest);

	return 0;
}