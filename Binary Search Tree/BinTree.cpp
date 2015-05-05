// File name: BinTree.h
// Author: Charles Fei
// Project: Binary Search Tree
// Date: 5/5/2014
// Description: Header file for implementation of Binary Search Tree class

#include <string>
#include <fstream>
#include <iostream>
#include "BinNode.h"
using namespace std;

//Class Constructor
//Post: Empty BinTree created
template <typename ItemType>
BinTree<ItemType>::BinTree() : myRoot(nullptr)
{
}

//Copy Constructor
//Pre: BinTree rhs is a valid BinTree
//Post: Object is copy of rhs, but has own set of nodes
template <typename ItemType>
BinTree<ItemType>::BinTree(const BinTree<ItemType>& rhs) : myRoot(nullptr)
{
	if (!rhs.isEmpty())
	{
		myRoot = new BinNode<ItemType>(*rhs.myRoot);	//call BinNode copy ctor
	}
}

//Destructor
template <typename ItemType>
BinTree<ItemType>::~BinTree()
{
	delete myRoot;
	myRoot = nullptr;
}

//Assignment Operator
template <typename ItemType>
const BinTree<ItemType>& BinTree<ItemType>::operator=(const BinTree<ItemType>& rhs)
{
	if (rhs != this)
	{
		BinNode<ItemType>* tmp = new BinNode<ItemType>(*rhs.myRoot);
		std::swap(this->myRoot, tmp);
	}
	return this;
}

//isEmpty
//Pre: Object is a valid BinTree
//Post: Returns true if BinTree, false otherwise
template <typename ItemType>
bool BinTree<ItemType>::isEmpty() const
{
	return (myRoot == nullptr);
}

//insert
//Pre: data is a valid item to insert
//Post: New node is created with data, or data is ignored if it already exists in tree
template <typename ItemType>
void BinTree<ItemType>::insert(const ItemType& data)
{
	if (isEmpty())
	{
		myRoot = new BinNode<ItemType>(data);
	}
	else
	{
		myRoot->insert(data);
	}
}

//remove
//Pre: data is a valid item to remove
//Post: Node containing data removed from BinTree
template <typename ItemType>
void BinTree<ItemType>::remove(const ItemType& data)
{
	if (!isEmpty())
	{
		myRoot->remove(data);
	}
}

//search
//Pre: data is a valid item to search
//Post: True is returned if node containing data exists in BinTree, false is returned otherwise
template <typename ItemType>
bool BinTree<ItemType>::search(const ItemType& data) const
{
	if (!isEmpty())
	{
		return myRoot->search(data);
	}

	return false;
}

//printInOrder
//Pre: Object is a valid non-empty BinTree
//Post: Performs an in-order traversal of the BinTree and prints the data
template <typename ItemType>
void BinTree<ItemType>::printInOrder()
{
	if (!isEmpty())
	{
		myRoot->printInOrder();
	}
	else
	{
		cout << "BinTree is empty." << endl;
	}
}

//printPreOrder
//Pre: Object is a valid non-empty BinTree
//Post: Performs an pre-order traversal of the BinTree and prints the data
template <typename ItemType>
void BinTree<ItemType>::printPreOrder()
{
	if (!isEmpty())
	{
		myRoot->printPreOrder();
	}
	else
	{
		cout << "BinTree is empty." << endl;
	}
}

//printPostOrder
//Pre: Object is a valid non-empty BinTree
//Post: Performs an post-order traversal of the BinTree and prints the data
template <typename ItemType>
void BinTree<ItemType>::printPostOrder()
{
	if (!isEmpty())
	{
		myRoot->printPostOrder();
	}
	else
	{
		cout << "BinTree is empty." << endl;
	}
}