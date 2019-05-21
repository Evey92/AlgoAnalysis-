// SortingAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

/******************************************************************************************

  Sorting Functions

******************************************************************************************/

/*
 * @brief Function to sort a vector using insertion sort
 */
std::vector<int> insertionSort(std::vector<int> vecToSort)
{
  std::vector<int>::iterator IT;
  std::vector<int>::iterator pivot;

  for (IT = vecToSort.begin() + 1; IT != vecToSort.end(); ++IT)
  {
    pivot = std::upper_bound(vecToSort.begin(), IT, *IT);

    std::rotate(pivot, IT, IT + 1);
  }

  return vecToSort;
}

/*
 * @brief Function to sort a vector using QuickSort
 */
std::vector<int> quickSort(std::vector<int> vecToSort)
{

  std::vector<int>::iterator pivot;

  for (auto IT = vecToSort.begin() + 1; IT != vecToSort.end(); ++IT)
  {
    pivot = std::upper_bound(vecToSort.begin(), IT, *IT);

    std::rotate(pivot, IT, IT + 1);
  }

  return vecToSort;
}

/******************************************************************************************

  Utility Functions

******************************************************************************************/

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
 * @brief Function to create a vector filled with random numbers
 */
std::vector<int> createAscendingVector(int size)
{
  std::vector<int> newVec;

  for (int i = 0; i < size; ++i)
  {
    newVec.push_back(size);
  }

  return newVec;
}

/*
 * @brief Function to create a vector filled with descending numbers
 */
std::vector<int> createDescendingVector(int size)
{
  std::vector<int> newVec;
  int num = size;

  for (int i = 0; i < size; ++i)
  {
    newVec.push_back(num);
    --num;
  }

  return newVec;
}

/*
 * @brief Function to print a vector
 */
void printVec(std::vector<int> vecToPrint) {

  std::cout << "Array: [";
  for (int i = 0; i < vecToPrint.size(); ++i)
  {
    std::cout << vecToPrint[i] << ", ";
  }

  std::cout << "]" << std::endl;

}
/*
 * @brief Function to break a vector in 2 with a pivot
 */
void partition(std::vector<int> vecToPartition) {

  std::vector<int>::iterator pivot = vecToPartition.end();

  for (auto IT = vecToPartition.begin(); IT != vecToPartition.end(); ++IT)
  {
    if (*IT <= *pivot) {
      //std::iter_swap();
    }
  }

}

int main()
{
  srand(time(NULL));

  std::vector<int> myVec = createDescendingVector(100);
  std::vector<int> sortedVec;
  std::cout << "Random Array: ";
  printVec(myVec);
  std::cout << "\n\n";

  std::cout << "Ordered array: ";
  sortedVec = insertionSort(myVec);
  printVec(sortedVec);
  std::cout << "\n\n";
}

