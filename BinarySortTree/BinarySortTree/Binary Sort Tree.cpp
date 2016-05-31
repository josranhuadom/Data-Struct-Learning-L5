#include<iostream>
using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;
	InfoType otherinfo;
}ElemType;
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild, *rchild;
}BSTNode,  BSTree;

ElemType e;

void InsertBST(BSTree *&T, ElemType e)
{
	if (!T)
	{
		BSTNode * S = new BSTNode;
		S->data = e;
		S->lchild = S->rchild = NULL;
		T = S;
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);
	else if (e.key > T->data.key)
		InsertBST(T->rchild, e);
}

void CreatBST(BSTree *&T)
{
	T = NULL;
	cin >> e.key;
	if (e.key == '#')
	{
		cout << "没有建立数组" << endl;
		return;
	}
	else
	{
		InsertBST(T, e);
		cin >> e.key;
	}
}

int main()
{
	BSTree *T = new BSTree;
	CreatBST(T);
}