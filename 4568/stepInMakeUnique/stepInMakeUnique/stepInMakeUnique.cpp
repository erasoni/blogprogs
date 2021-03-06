// stepInMakeUnique.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <memory>
#include <vector>
#include <set>

// Taken from https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
int gid;
struct Vec3
{
	int x, y, z;
	Vec3() : x(0), y(0), z(0) {
		std::cout << "Vec3 constructor: " << gid++ << std::endl;
	}
	Vec3(int x, int y, int z) :x(x), y(y), z(z) { 
		std::cout << "Vec3 constructor: " << gid++ << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& os, Vec3& v) {
		return os << '{' << "x:" << v.x << " y:" << v.y << " z:" << v.z << '}';
	}
};

int main()
{
	// other than std::make_unique must not be stepped into
	std::vector<int> vi;
	vi.push_back(10);

	std::set<int> si;
	si.insert(100);

	std::cout << "DON'T STEP INTO" << std::endl;

	// make_unique must be stepped in

	// Use the default constructor.
	std::unique_ptr<Vec3> v1 = std::make_unique<Vec3>();
	// Use the constructor that matches these arguments
	std::unique_ptr<Vec3> v2 = std::make_unique<Vec3>(0, 1, 2);
	// Create a unique_ptr to an array of 5 elements
	std::unique_ptr<Vec3[]> v3 = std::make_unique<Vec3[]>(5);

	std::cout << "make_unique<Vec3>():      " << *v1 << '\n'
		<< "make_unique<Vec3>(0,1,2): " << *v2 << '\n'
		<< "make_unique<Vec3[]>(5):   " << '\n';
	for (int i = 0; i < 5; i++) {
		std::cout << "     " << v3[i] << '\n';
	}
}


