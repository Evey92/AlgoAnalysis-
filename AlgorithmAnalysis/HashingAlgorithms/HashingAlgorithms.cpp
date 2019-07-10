// HashingAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <vector>

#include "HashTableMap.h"
#include "kraRNG.h"

#pragma region Utility_functions

/*
 * @brief Function to create a vector filled with random numbers
 */
float fRandRange(float a, float b)
{
  return ((b - a)*((float)rand() / RAND_MAX)) + a;
}

/*
 * @brief Function to create a vector filled with random numbers
 */
std::vector<int> createRandomVector(int size)
{
  std::vector<int> newVec;

  for (int i = 0; i < size; ++i)
  {
    int num = rand() % 100;
    newVec.push_back(num);
  }

  return newVec;
}

/*
 * @brief Function to print a vector
 */
void 
printVec(std::vector<int> vecToPrint) {

  std::cout << "Data: [";
  for (int i = 0; i < vecToPrint.size(); ++i)
  {
    if (i == vecToPrint.size()-1)
    {
      std::cout << vecToPrint[i];
    }
    else
    {
      std::cout << vecToPrint[i] << ", ";

    }
  }

  std::cout << "]" << std::endl;
}
#pragma endregion Utility_functions

#pragma region Hash_Functions

int hashFunctionTemp(int key)
{
  int hashedKey = 0;

  hashedKey = hashedKey % 10;
  return hashedKey;
}

int multiplicativeHashFunc(int key, int tableSize)
{
  int hashedKey = 0;
  float A = fRandRange(0, 1);

  hashedKey = floor(tableSize*(key*A - floor(key*A)));
  

  return hashedKey;
}

#pragma endregion Hash_Functions

int main()
{
  kraRandom r;
  srand((unsigned)time(NULL));
  
  const int tableSize = 67;
  int hashKey = 0;
  std::vector<int> dataVec;

  HashTableMap<int, int, tableSize> hashTable;

  hashTable.setHashFunction(multiplicativeHashFunc);

  dataVec = createRandomVector(100);

  std::cout << "Data to be hashed: \n";
  printVec(dataVec);

  for (std::vector<int>::iterator it = dataVec.begin(); it != dataVec.end(); ++it)                              
  {
    hashTable.put(*it);
  }


  hashTable.showTable();

}
