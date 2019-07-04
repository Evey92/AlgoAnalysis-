// HashingAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void printHello()
{
  std::cout << "Hello World!\n";

}

void printPoopy()
{
  std::cout << "poop\n";
}

int main()
{
  void (*printFunc)();

  printFunc = &printHello;

  printFunc();

  printFunc = &printPoopy;

  printFunc();
}
