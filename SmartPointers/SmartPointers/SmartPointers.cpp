// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <map>
class SmartPointers
{
public:
	SmartPointers();
	~SmartPointers();
	void log();
	int iValue = -1;
private:

};

SmartPointers::SmartPointers()
{
	std::cout << "in Constructor" << std::endl;
}

SmartPointers::~SmartPointers()
{
	std::cout << "in destructor" << std::endl;
}

void SmartPointers::log() {
	std::cout << "in the logs" << std::endl;
}
int main()
{
	std::map<int, std::unique_ptr <SmartPointers>> oMap;
	std::map<int, std::shared_ptr <SmartPointers>> oMap2;
	{
		std::unique_ptr <SmartPointers> pUniquePtr = std::make_unique<SmartPointers>();
		pUniquePtr->iValue = 10;
		pUniquePtr->log();
	}
	{
		std::shared_ptr <SmartPointers> pSharedPtr = std::make_shared<SmartPointers>();
		pSharedPtr->iValue = 20;
		pSharedPtr->log();
		oMap2[0] = pSharedPtr;
		std::shared_ptr <SmartPointers> pSharedPtr2;
		pSharedPtr2 = oMap2[0];
		std::cout << "output from sharedMap : " << pSharedPtr2->iValue << std::endl;
	}
	std::shared_ptr <SmartPointers> pSharedPtr3;
	pSharedPtr3 = oMap2[0];
	std::cout << "output from sharedMap : " << pSharedPtr3->iValue << std::endl;
}
