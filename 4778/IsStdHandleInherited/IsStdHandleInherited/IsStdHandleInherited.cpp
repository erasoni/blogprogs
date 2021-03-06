// IsStdHandleInherited.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <iostream>

using namespace std;
int main()
{
	DWORD dwFlags = 0;
	if (!GetHandleInformation(GetStdHandle(STD_INPUT_HANDLE), &dwFlags))
	{
		cerr << "Error" << endl;
		return 1;
	}
	cout << "STD_INPUT_HANDLE is inherited? " << endl;
	if (dwFlags & HANDLE_FLAG_INHERIT)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	dwFlags = 0;
	if (!GetHandleInformation(GetStdHandle(STD_OUTPUT_HANDLE), &dwFlags))
	{
		cerr << "Error" << endl;
		return 1;
	}
	cout << "STD_OUTPUT_HANDLE is inherited? " << endl;
	if (dwFlags & HANDLE_FLAG_INHERIT)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

    return 0;
}

