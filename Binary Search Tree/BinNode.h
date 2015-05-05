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
public:
	BinNode(const ItemType & data); //ctor
	BinNode(const BinNode & rhs); //copy ctor
	~BinNode();
	const BinNode & operator=(const BinNode& rhs);
	void insert(const ItemType & data);
};

#endif