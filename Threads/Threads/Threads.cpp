// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
static bool bFlag = false;

static void Dowork() {
	while (bFlag == false) {
		std::cout << "Working ...." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
int main()
{
	//Creats Thread and it works parallely with main thread
	std::thread worker(Dowork);
	std::cin.get();
	bFlag = true;
	//Join will hold execution till the worker thread completes execution.
	worker.join();
	std::cin.get();
    std::cout << "Hello World!\n";
}