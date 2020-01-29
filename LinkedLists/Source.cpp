#include <iostream>
#include <vector>
#include "tForwardList.h"



int main()
{
	tList<int> appleBundles;


	appleBundles.push_front(6);
	appleBundles.push_front(5);
	appleBundles.push_front(4);
	appleBundles.push_front(3);
	appleBundles.push_front(2);
	appleBundles.push_front(1);

	appleBundles.push_back(10);
	appleBundles.push_back(8);
	appleBundles.push_back(9);
	appleBundles.push_back(10);

	tList<int> copyList(appleBundles);

	copyList.resize(5);

	copyList.push_front(0);

	copyList.pop_back();
	copyList.pop_front();


	copyList.remove(10);

	copyList.resize(14);





	int x = copyList.front();
	int y = copyList.back();
	bool b = copyList.empty();
	const int z = copyList.front();
	const int w = copyList.back();

	appleBundles.clear();




	//---------------------------------------------------------------iterators

	//iterator iter(head);

	//appleBundles.begin();
	//appleBundles.end();
	//appleBundles.operator=();







	return 0;
}