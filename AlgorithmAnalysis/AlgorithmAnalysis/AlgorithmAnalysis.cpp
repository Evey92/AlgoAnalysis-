// AlgorithmAnalysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> coinsTogive;
  int coin[5];
  int money = 0;
  int totalMoney = 0;
  int moneyTogive = 0;
 
  coin[0] = 10;
  coin[1] = 5;
  coin[2] = 2;
  coin[3] = 1;

  std::cout << "How much money do you need?\n";
  std::cin >> money;

  totalMoney = money;
  while (moneyTogive < totalMoney) {
    
    if (money >= coin[0]) {
      moneyTogive += coin[0];
      money -= coin[0];
      coinsTogive.push_back(coin[0]);
    }
    else if (money >= coin[1])
    {
      moneyTogive += coin[1];
      money -= coin[1];
      coinsTogive.push_back(coin[1]);

    }
    else if (money >= coin[2])
    {
      moneyTogive += coin[2];
      money -= coin[2];
      coinsTogive.push_back(coin[2]);

    }
    else if (money >= coin[3])
    {
      moneyTogive += coin[3];
      money -= coin[3];
      coinsTogive.push_back(coin[3]);

    }
  }

  std::cout << "Here's: " << moneyTogive << " in these coins: \n";

  for (std::vector<int>::iterator it = coinsTogive.begin(); it != coinsTogive.end(); ++it)
  {
    std::cout << *it << ",\n";
  }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
