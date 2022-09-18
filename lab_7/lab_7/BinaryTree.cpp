#include "BinaryTree.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "BinaryTree.h"
using namespace std;
void BinaryTree::Insert(int data)
{
	if (firstNode)
	{
		auto node = firstNode;
		while (true)
		{
			if (node->getValue() > data)
			{
				auto left = node->getLeft();
				if (left)
				{
					node = left;
					continue;
				}
				else
				{
					Insert(node, data);
					break;
				}
			}
			auto right = node->getRight();
			if (right)
				node = right;
			else
			{
				Insert(node, data);
				break;
			}
		}
	}
	else firstNode = new TreeNode(data);
}
BinaryTree::TreeNode* BinaryTree::Search(int data) const
{
	if (firstNode)
	{
		auto node = firstNode;
		while (!Search(node, data))
		{
			auto nodeValue = node->getValue();
			if (nodeValue > data)
			{
				auto left = node->getLeft();
				if (left)
					node = left;
				else
					return nullptr;
			}
			else
			{
				auto right = node->getRight();
				if (right)
					node = right;
				else
					return nullptr;
			}
		}
		return node;
	}
	return nullptr;
}
void BinaryTree::Print() const
{
	if (firstNode)
	{
		TreeNode** nodes = new TreeNode*[1]{ firstNode };
		int nodesCurrentCount = 1;
		for (int level = 1; nodesCurrentCount; level++)
		{
			TreeNode** newNodes = new TreeNode *[nodesCurrentCount * 2];
			int index = 0;
			cout << "������� �� ������" << level << ":" << endl;
			for (int i = 0; i < nodesCurrentCount; i++)
			{
				auto node = nodes[i];
				cout << node->getValue() << ' ';
				if (node->getLeft())
					newNodes[index++] = node->getLeft();
				if (node->getRight())
					newNodes[index++] = node->getRight();
			}
			nodesCurrentCount = index;
			delete[] nodes;
			nodes = newNodes;
			cout << endl;
			if (index == 0)
				cout << "������ ��������� ������ = " << level << endl;
		}
		delete[] nodes;
	}
	else cout << "������ ������";
}
void BinaryTree::Insert(TreeNode* node, int data)
{
	assert(node);
	if (node->getValue() > data)
	{
		assert(node->getLeft() == nullptr);
		node->setLeft(new TreeNode(data));
	}
	else
	{
		assert(node->getRight() == nullptr);
		node->setRight(new TreeNode(data));
	}
}
bool BinaryTree::Search(TreeNode* node, int data) const
{
	assert(node);
	return node->getValue() == data;
}