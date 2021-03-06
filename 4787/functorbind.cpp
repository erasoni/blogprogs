// functorbind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void testfunc(int i1, int i2)
{
	printf("%d %d\n", i1, i2);
}


int main()
{
	// testfuncの第一引数、第二引数ともにfuncの引数を渡す。
	auto func0 = bind(testfunc, std::placeholders::_1, std::placeholders::_2);
	func0(100, 101);

	// testfuncの第一引数に9999を渡し、第二引数にはfuncの引数を渡す。
	auto func1 = bind(testfunc, 9999, std::placeholders::_1);
	func1(100);

	// testfuncの第一引数にviの要素を渡し、第二引数には7777を渡す。
	vector<int> vi = { 123, 345, 567 };
	auto func2 = bind(testfunc, std::placeholders::_1, 7777);
	for_each(vi.begin(), vi.end(), func2);
    return 0;
}

