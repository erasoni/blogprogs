// functor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class SimpleFunctor {
public:
	void operator()() {
		cout << "Hello" << endl;
	}
};

int main()
{
	SimpleFunctor simpleFunctor;
	simpleFunctor();
    return 0;
}

