// LCSProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

template< class T, class Alloc = std::allocator<T>>
using Vector = std::vector<T, Alloc>;
using String = std::string;

int max(int a, int b) {
  return (a > b) ? a : b;
}

void
dynamicLCS(String str1, String str2, int m, int n) {

  Vector<Vector<unsigned int>> intVec;

  intVec.resize(m + 1);

  for (auto& it : intVec) {
    it.resize(n + 1);
  }
 
  for (unsigned int i = 0; i <= m; i++)
  {
    for (unsigned int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0) {
        intVec[i][j] = 0;
      }
      else if (str1[i - 1] == str2[j - 1]) {
        intVec[i][j] = intVec[i - 1][j - 1] + 1;
      }
      else {
        intVec[i][j] = max(intVec[i - 1][j], intVec[i][j - 1]);
      }
    }
  }

  int index = intVec[m][n];

  String lcs("");
  lcs.resize(index + 1);
  lcs[index] = '\0';

  int i = m, j = n;

  while (i > 0 && j > 0)
  {
    if (str1[i-1] == str2[i-1])
    {
      lcs[index - 1] = str1[i - 1];
      --i;
      --j;
      --index;
    } 
    else if (intVec[i-1][j] > intVec[i][j-1])
    {
      --i;
    }
    else
    {
      --j;
    }
  }

  std::cout << "The longest subsequence between " << str1 << " and " << str2 << " is : " << lcs << "\n";
}

Vector<Vector<char>>
bruteLCS(std::string str, int number) {
  
  int n = str.length();
  int numSequencias = pow(2, n);

  Vector<std::vector<char>> sequences;

  for (unsigned int i = 1; i < numSequencias; ++i) {
    
    Vector<char> sequence;
    for (unsigned int j = 0; j < n; ++i) {
      if (i & (1 << j)) {
        sequence.push_back(str[j]);
      }
    }
    sequences.push_back(sequence);
  }
  return sequences;
}

Vector<char>
compareSubsequence(Vector<Vector<char>> sub1, Vector<Vector<char>> sub2) {
  
  int n1 = sub1.size();
  int n2 = sub2.size();

  Vector<char> LCS;
  for (unsigned int i = 0; i < n1; ++i) {
    for (unsigned int j = 0; j < n2; ++i) {
      if (sub1[i] == sub2[j]) {
        if (LCS.size() < sub1[i].size()) {
          LCS = sub1[i];
        }    
      }
    }
  }

  return LCS;
}

void printCharVector(Vector<char> vecToPrint) {
  for (auto i = vecToPrint.begin(); i != vecToPrint.end(); ++i) {
    std::cout << *i << ', ';
  }
}

int main()
{
  bool brute = false;

  String sequence1("TTCGCATCGGGTTG");
  String sequence2("TGACCGTGTGTCACG");
  Vector<char> lcs;

  auto start = std::chrono::high_resolution_clock::now();
  if (brute) {
    Vector<Vector<char>> sub1 = bruteLCS(sequence1, 1);
    Vector<Vector<char>> sub2 = bruteLCS(sequence2, 2);
    lcs = compareSubsequence(sub1, sub2);
    std::cout << "The longest subsequence between " << sequence1 << " and " << sequence2 << " is : ";
    printCharVector(lcs);
  }
  else
  {
    dynamicLCS(sequence1.c_str(), sequence2, sequence1.size(), sequence2.size());
  }

  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout <<"\nExecution time: " << duration.count() << std::endl;
}

