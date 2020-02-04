#include "Sort.h"

Sort::Sort()
{
}

Sort::~Sort()
{
}

void Sort::swap(std::vector<int>& arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void Sort::bubbleSort(std::vector<int>& arr)
{
	bool isSorted = false;
	int lastUnsorted = arr.size();

	while (!isSorted)
	{
		isSorted = true;
		for (int i = 0; i < lastUnsorted; i++)
		{
			if (i + 1 < arr.size() && arr[i] > arr[i + 1])
			{
				swap(arr, i, i + 1);
				isSorted = false;
			}
		}
		lastUnsorted--;
	}
}