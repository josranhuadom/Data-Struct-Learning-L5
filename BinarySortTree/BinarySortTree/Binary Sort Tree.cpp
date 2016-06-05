//二叉排序树
#include<iostream>
using namespace std;

typedef int KeyType;
typedef int InfoType;

//二叉排序树的二叉链表存储表示
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

ElemType e;    //新建结点e以储存输入的值

//当二叉排序树 T 中不存在关键字等于 e.key 的数据元素是，则插入该元素
void InsertBST(BSTree *&T, ElemType e)
{
	if (!T)
	{//这是找到插入位置的情况，此时是最后一次进行递归调用
		BSTNode * S = new BSTNode;      //生成新节点 *S
		S->data = e;                                      //新节点 *S 的数据域置为 e
		S->lchild = S->rchild = NULL;       //新节点 *S 作为叶子节点
		T = S;                                                  //把新节点 *S 链接到已找到的插入位置
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);                   //将 *S 插入左子树
	else if (e.key > T->data.key)
		InsertBST(T->rchild, e);                  //将 *S 插入右子树
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