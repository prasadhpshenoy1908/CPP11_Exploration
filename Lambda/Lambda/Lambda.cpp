// Lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void funcptr(T& avec, void (*FUNCNAME)(int)) {
	for (int value : avec) {
		FUNCNAME(value);
	}
}
template <typename T>
int sum(T& avec) {
	auto iSum = 0;
	for (int value : avec) {
		iSum += value;
	}
	return iSum;
}

int main()
{
	int a = 5;
	vector<int> aVector = { 3,4,5,6,7,8,9 };

	//simple lambda functionality
	auto func = [](int value) {return value + 10; };
	std::cout << func(10) << std::endl;
	
	//Lambda inside for loop
	auto func2 = [a](int value) {std::cout << value + a << std::endl; return ; };
	for (int items : aVector) {
		func2(items);
	}
	
	//Passing lambda as a function point to other function.
	auto func3 = [](int value) {std::cout << value + 10 << std::endl; return; };
	funcptr(aVector, func3);

	//Using function pointer
	int (*FUNCPTR)(std::vector<int>&);
	FUNCPTR = &sum;
	std::cout << "Sum is :" << FUNCPTR(aVector) << std::endl;

	//using lambda to sort elements in array
	std::sort(aVector.begin(), aVector.end(), [](int a, int b) {return a > b; });
	std::cout << "sorted array : " << std::endl;
	for (int iValue : aVector) {
		std::cout << iValue;
	}

}