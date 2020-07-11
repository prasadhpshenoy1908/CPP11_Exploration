// CPP11Samples_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Base {
private:
	int a;
public:
	Base() {
		std::cout << "Base Constructor" << std::endl;
	}
	Base(int number) {
		a = number;
	}

	Base(float number) = delete;

	virtual ~Base() {
		std::cout << "Base destructor" << std::endl;
	}

	virtual void func() {
		std::cout << "in base class" << std::endl;
	}
	virtual void func(int number) {
		std::cout << "in base class. Number is" << number << std::endl;
	}
};

class derived1 : public Base {
public:

	derived1() {
		std::cout << "Derived1 Constructor" << std::endl;
	}
	derived1(int number) = delete;

	~derived1() {
		std::cout << "Derived1 destructor" << std::endl;
	}

	void func() override {
		std::cout << "in derived class" << std::endl;
	}
	//below will throw a compilation error as the parameters are different
	/*void func(float number) override{
		std::cout << "in derived class. Number is" << number << std::endl;
	}*/
};

int main()
{
	Base* ptr = nullptr;

	ptr = new Base(10);
	ptr -> func();
	delete ptr;
	ptr = nullptr;

	//below code gives compilation error
	//constructor with float isnt allowed
	//ptr = new Base(10.3);

	ptr = new derived1();
	ptr->func(1);
	ptr->func(1.2);
	delete ptr;
	ptr = nullptr;

	//below code gives compilation error
	//constructor with int isnt allowed
	ptr = new derived1(10);
}