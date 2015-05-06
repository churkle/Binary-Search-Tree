// File name: BinNode.h
// Author: Charles Fei
// Project: Binary Search Tree
// Date: 5/5/2014
// Description: Header file for implementation of Binary Search Tree node

#include <string>
#include <fstream>
#include <iostream>
#include "BinTree.h"
#include "BinNode.h"
using namespace std;

int main()
{
	BinTree<int> myTree;
	ifstream file("input.txt");

	int num;
	while (file >> num)
	{
		myTree.insert(num);
	}

	cout << "Here are the numbers in the Binary Search Tree: ";
	myTree.printInOrder();

	system("pause");
}