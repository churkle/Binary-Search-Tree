// File name: BinNode.h
// Author: Charles Fei
// Project: Binary Search Tree
// Date: 5/5/2014
// Description: Header file for implementation of Binary Search Tree node

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//Class Constructor
template <typename ItemType>
BinNode<ItemType>::BinNode(const ItemType& data) : item(data), left(nullptr), right(nullptr)
{
}

//Copy Constructor
template <typename ItemType>
BinNode<ItemType>::BinNode(const BinNode<ItemType> & rhs) : item(rhs.item), left(nullptr), right(nullptr)
{
	if (rhs.left != nullptr)
	{
		left = new BinNode<ItemType>(*rhs.left);
	}

	if (rhs.right != nullptr)
	{
		right = new BinNode<ItemType>(*rhs.right);
	}
}

//Destructor
template <typename ItemType>
BinNode<ItemType>::~BinNode()
{
	delete left;
	delete right;
	left = right = nullptr;
}

//Assignment Operator
template <typename ItemType>
const BinNode<ItemType>& BinNode<ItemType>::operator =(const BinNode<ItemType>& rhs)
{
	if (this != rhs)
	{
		BinNode<ItemType>* tmp = new BinNode<ItemType>(rhs);
		std::swap(this->item, tmp->item);
		std::swap(this->left, tmp->left);
		std::swap(this->right, tmp->right);
		delete tmp;
		tmp = nullptr;
	}
	return this;
}

//insert
//Pre: data is a valid item to insert into sub-tree
//Post: New node is created in sub-tree with data, or data is ignored if it already exists in sub-tree
template <typename ItemType>
void BinNode<ItemType>::insert(const ItemType & data)
{
	if (data < item)
	{
		if (left != nullptr)
		{
			left->insert(data);
		}
		else
		{
			left = new BinNode<ItemType>(data);
		}
	}
	else if (data > item)
	{
		if (right != nullptr)
		{
			right->insert(data);
		}
		else
		{
			right = new BinNode<ItemType>(data);
		}
	}
}

//findSuccessor
//Finds the node that is next largest after the node it's called on
template <typename ItemType>
BinNode<ItemType>* BinNode<ItemType>::findSuccessor() const
{
	if (right != nullptr)
	{
		BinNodePtr tmp = right;
		while (tmp->left != nullptr)
		{
			tmp = tmp->left;
		}
		return tmp;
	}
	return nullptr;
}

//remove
//Pre: data is a valid item to remove from sub-tree
//Post: Node containing data removed from sub-tree, returns successor or nullptr if there is no successor or removal
template <typename ItemType>
BinNode<ItemType>* BinNode<ItemType>::remove(const ItemType& data) const
{
	if (data < item)
	{
		if (left == nullptr)
		{
			return nullptr;
		}

		if (left->item == data)
		{
			if (left->left == nullptr && left->right == nullptr)	//node to be removed is a leaf
			{
				delete left;
				left = nullptr;
				return nullptr;
			}
			else if (left->left == nullptr)		//node to be deleted has one child
			{
				BinNodePtr tmp = left;
				left = left->left;
				delete tmp;
				tmp = nullptr;
				return left;
			}
			else if (left->right == nullptr)	//node to be deleted has one child
			{
				BinNodePtr tmp = left;
				left = left->right;
				delete tmp;
				tmp = nullptr;
				return left;
			}
			else
			{
				BinNodePtr tmp = left->findSuccessor();	//node to be deleted has two children
				std::swap(left->item, tmp->item);
				delete tmp;
				tmp = nullptr;
				return left;
			}
		}
	}
	else if (data > item)
	{
		if (right == nullptr)
		{
			return nullptr;
		}

		if (right->item == data)
		{
			if (right->left == nullptr && right->right == nullptr)	//node to be removed is a leaf
			{
				delete right;
				right = nullptr;
				return nullptr;
			}
			else if (left->left == nullptr)		//node to be deleted has one child
			{
				BinNodePtr tmp = right;
				right = right->left;
				delete tmp;
				tmp = nullptr;
				return right;
			}
			else if (right->right == nullptr)	//node to be deleted has one child
			{
				BinNodePtr tmp = right;
				right = right->right;
				delete tmp;
				tmp = nullptr;
				return right;
			}
			else
			{
				BinNodePtr tmp = right->findSuccessor();	//node to be deleted has two children
				std::swap(right->item, tmp->item);
				delete tmp;
				tmp = nullptr;
				return right;
			}
		}
	}
}

//search
//Pre: data is a valid item to search in sub-tree
//Post: True is returned if node containing data exists in sub-tree, false is returned otherwise
template <typename ItemType>
bool BinNode<ItemType>::search(const ItemType& data) const
{
	if (data == item)
	{
		return true;
	}

	if (data < item)
	{
		if (left != nullptr)
		{
			return left->search(data);
		}
		else
		{
			return false;
		}
	}

	if (data > item)
	{
		if (right != nullptr)
		{
			return right->search(data);
		}
		else
		{
			return false;
		}
	}
}

//printInOrder
//Pre: Node is root of valid sub-tree
//Post: Performs an in-order traversal of the sub-tree and prints the data
template <typename ItemType>
void BinNode<ItemType>::printInOrder() const
{
	if (left != nullptr)
	{
		left->printInOrder();
	}

	cout << item << " ";

	if (right != nullptr)
	{
		right->printInOrder();
	}
}

//printPreOrder
//Pre: Node is root of valid sub-tree
//Post: Performs an in-order traversal of the sub-tree and prints the data
template <typename ItemType>
void BinNode<ItemType>::printPreOrder() const
{
	cout << item << " ";

	if (left != nullptr)
	{
		left->printPreOrder();
	}

	if (right != nullptr)
	{
		right->printPreOrder();
	}
}

//printPostOrder
//Pre: Node is root of valid sub-tree
//Post: Performs an in-order traversal of the sub-tree and prints the data
template <typename ItemType>
void BinNode<ItemType>::printPostOrder() const
{
	if (left != nullptr)
	{
		left->printPostOrder();
	}

	if (right != nullptr)
	{
		right->printPostOrder();
	}

	cout << item << " ";
}