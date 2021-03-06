#include <iostream>
#include <vector>

#include "Tree.h"

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

void
printVec(std::vector<int> vecToPrint) {

  std::cout << "Data: [";
  for (int i = 0; i < vecToPrint.size(); ++i)
  {
    if (i == vecToPrint.size() - 1)
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

int main()
{
  Tree myTree;
  int option;
  std::vector<int> dataVec = createRandomVector(10);
  std::cout << "Data to store in tree\n";
  printVec(dataVec);

  for (std::vector<int>::iterator it = dataVec.begin(); it != dataVec.end(); ++it)
  {
    myTree.insert(*it);
  }

  std::cout << "This is the binary three in order: \n";
  myTree.inOrder();

  while (true)
  {
    std::cout << "\nWhat do you want to do:\n1-Insert item\n2-Delete item\n3-Search for a node\n4-Print tree in order\nAnything else to exit.\n";
    std::cin >> option;
   
    switch (option)
    {
    case 1:
      std::cout << "Enter number to insert:\n";
      std::cin >> option;
      myTree.insert(option);
    	break;
    case 2:
      std::cout << "Enter number to delete:\n";
      std::cin >> option;
      myTree.deleteNode(option);
      break;
    case 3:
    {
      std::cout << "Enter number to search:\n";
      std::cin >> option;
      Node* searcheNode = myTree.search(option);
      std::cout << "My value is: " << searcheNode->getKey() << "\n";
      if (searcheNode->getParent() != nullptr) {
        std::cout << "My parent's is: " << searcheNode->getParent()->getKey() << "\n";
      }
      else {
        std::cout << "And I'm the root \n";
      }
    }
      break;
    case 4:
      myTree.inOrder();
      break;
    default:
      return 0;
      break;
    }
  }
}
