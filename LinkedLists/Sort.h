#pragma once
#include <vector>
class Sort
{
public:
	Sort();
	~Sort();
	void bubbleSort(std::vector<int> &arr);
	void swap(std::vector<int> &arr, int i, int j);
};

