// File name: BinTree.h
// Author: Charles Fei
// Project: Binary Search Tree
// Date: 5/5/2014
// Description: Header file for implementation of Binary Search Tree class

#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <string>
#include <fstream>
#include <iostream>
#include "BinNode.h"
using namespace std;

template <typename ItemType>
class BinTree
{
private:
	BinNode<ItemType>* myRoot;

public:
	BinTree(); //ctor
	BinTree(const BinTree& rhs); //copy ctor
	~BinTree(); //dtor
	const BinTree& operator=(const BinTree& rhs);	//assignment operator
	bool isEmpty() const;
	void insert(const ItemType& data);
	void remove(const ItemType& data);
	bool search(const ItemType& data) const;
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
};

#include "BinTree.cpp"
#endif