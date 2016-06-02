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
	cout << "请输入想要插入的值，-1结束" << endl;
	cin >> e.key;
	while (e.key  != EOF)
	{
		InsertBST(T, e);
		cout << "请继续输入想要插入的值，-1结束" << endl;
		cin >> e.key;
	} 
	cout << "二叉树建立结束" << endl << endl;
}

//中序遍历
void InOrderTraversal(BSTree *T)
{
	if (T)
	{
		InOrderTraversal(T->lchild);
		cout << T->data.key << " ";
		InOrderTraversal(T->rchild);
	}
}

int main()
{
	BSTree *T = new BSTree;
	CreatBST(T);
	if (T == NULL)
		cout << "没有建立二叉树" << endl;
	else
	{
		cout << "中序遍历结果" << endl;
		InOrderTraversal(T);
	}

	cout << endl;
	system("pause");
}