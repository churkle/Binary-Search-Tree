// File name: BinNode.h
// Author: Charles Fei
// Project: Binary Search Tree
// Date: 5/5/2014
// Description: Header file for implementation of Binary Search Tree Node

#ifndef BIN_NODE_H
#define BIN_NODE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

template <typename ItemType>
class BinNode
{
private:
	typedef BinNode * BinNodePtr;
	ItemType item;
	BinNodePtr left;
	BinNodePtr right;
	BinNodePtr findSuccessor() const;
public:
	BinNode(const ItemType & data); //ctor
	BinNode(const BinNode & rhs); //copy ctor
	~BinNode();
	const BinNode & operator=(const BinNode& rhs);
	void insert(const ItemType & data);
	BinNodePtr remove(const ItemType& data) const;
	bool search(const ItemType& data) const;
	void printInOrder() const;
	void printPreOrder() const;
	void printPostOrder() const;
};

#endif