#include <iostream>
#include <atlbase.h>
#include <atlwin.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "treewindow.h"
using namespace std;

typedef struct Node
{
	Node* left;
	Node* right;
	string data;
} ;

typedef struct { //树根
	Node* root=NULL;
} Tree;

void NodeInfoCallback(void* context, void* node_, int hierarchy, NodeInfo* nodeInfo)
{
	auto x = (Node*)(node_);

	nodeInfo->left = x->left;           // 设置左节点
	nodeInfo->right = x->right;         // 设置右节点
	_stprintf_s(nodeInfo->Label, "%s", (x->data).c_str());    // 需要显示的文本
	nodeInfo->ColorFill = RGB(105, 255, 97);           // 填充色
	nodeInfo->ColorLabel = RGB(0, 0, 0);          // 文本颜色
	nodeInfo->ColorBorder = RGB(255,0 ,0);        // 边框颜色
}

void insert(Tree* tree, string value)//创建树
{
	Node* node = new Node;//创建一个节点
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL)//判断树是不是空树
	{
		tree->root = node;
	}
	else {//不是空树
		Node* temp = tree->root;//从树根开始
		while (temp != NULL)
		{

			if (value.compare(temp->data) < 0)//小于就进左儿子
			{
				if (temp->left == NULL)
				{
					temp->left = node;
					return;
				}
				else {//继续判断
					temp = temp->left;
				}
			}
			else {//否则进右儿子

				if (temp->right == NULL)
				{
					temp->right = node;
					return;
				}
				else {//继续判断
					temp = temp->right;
				}
			}
		}
	}
	return;
}

void inorder(Node* node)//树的中序遍历
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << (node->data) << " ";
		inorder(node->right);
	}
}
void display(Tree tr)
{
	TreeWindow wnd;
	wnd.DisplayBinaryTree(tr.root, NodeInfoCallback, nullptr);
	system("pause");
}


int main()
{

	Tree tree;
	//tree.root=NULL;//创建一个空树
	int n = 2;
	for (int i = 0; i < n; i++)//输入n个数并创建这个树
	{
		string temp;
		cin >> temp;
		insert(&tree, temp);
	}
	inorder(tree.root);//中序遍历
	cout << endl;
	display(tree);
	return 0;
}