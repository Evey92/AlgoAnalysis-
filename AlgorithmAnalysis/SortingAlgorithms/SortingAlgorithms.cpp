// SortingAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

/******************************************************************************************

  Sorting Functions

******************************************************************************************/

/*
 * @brief Function to sort a vector using bubble sort
 */
std::vector<int> bubbleSort(std::vector<int> vecToSort)
{
  int n = vecToSort.size();

  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = 0; j < n-i-1; ++j)
    {
      if (vecToSort[j] > vecToSort[j+1])
      {
        std::swap(vecToSort[j], vecToSort[j + 1]);
      }
    }
  }

  return vecToSort;
}

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
std::vector<int> mergeSort(std::vector<int> vecToSort)
{

  std::vector<int>::iterator pivot;

  for (auto IT = vecToSort.begin() + 1; IT != vecToSort.end(); ++IT)
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

/*
 * @brief Function to sort a vector using CountSort
 */
std::vector<int> countSort(std::vector<int> vecToSort)
{

  std::vector<int>::iterator pivot;

  for (auto IT = vecToSort.begin() + 1; IT != vecToSort.end(); ++IT)
  {
    pivot = std::max_element(vecToSort.begin(), vecToSort.end());
    pivot = std::min_element(vecToSort.begin(), vecToSort.end());
  }

  return vecToSort;
}

/******************************************************************************************

  Searching Functions

******************************************************************************************/

/*
 * @brief Function to search for a number in a vector using linear search
 * @param The vector that'll be used to search
 * @param The number 
 */
void linearSearch(std::vector<int> vecForSearch, int numToSearch)
{
  std::vector<int>::iterator IT = vecForSearch.begin();

  for (IT; IT != vecForSearch.end(); IT++)
  {
    if (*IT == numToSearch)
    {
      std::cout << IT - vecForSearch.begin();
      return;
    }
  }
  
  std::cout << "The number couldn't be found in the given vector.\n";

}

/*
 * @brief Function to search for a number in a vector using binary search
 * @param The vector that'll be used to search
 * @param The number
 */
void binarySearch(std::vector<int> vecForSearch, int numToSearch)
{
  std::vector<int>::iterator IT = vecForSearch.begin();

  int L = 0;
  int R = vecForSearch.size();
  int mid;
  bool isFound;

  while (L <= R)
  {
    mid = L + (R - 1) / 2;

    if (vecForSearch[mid] == numToSearch)
    {
      std::cout << "The number is at index: " << mid << "\n";
      isFound = true;
      return;
    }
    else if (vecForSearch[mid] < numToSearch)
    {
      L = mid + 1;
    }
    else
    {
      R = mid - 1;
    }
  }

  std::cout << "The number couldn't be found in the given vector.\n";

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
 * @brief Function to merge 2 vectors
 */
void merge(std::vector<int> vecToPrint) {

  

}


int main()
{
  srand(time(NULL));
  int num;

  std::vector<int> myVec = createRandomVector(256);
  std::vector<int> sortedVec;
  std::cout << "Random Array: ";
  printVec(myVec);
  std::cout << "\n\n";

  std::cout << "Ordered array: ";
  sortedVec = bubbleSort(myVec);
  printVec(sortedVec);
  std::cout << "\n\n";

  std::cout << "Enter a number to search in the vector: \n";
  std::cin >> num;
  
  if (num > 99)
  {
    while (num > 99)
    {
      std::cout << "The number needs to be lees than 100.\nPlease nter a number to search in the vector: \n";
      std::cin >> num;
    }
  }

  linearSearch(sortedVec, num);
}

