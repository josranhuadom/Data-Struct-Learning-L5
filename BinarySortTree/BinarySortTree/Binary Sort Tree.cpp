//����������
#include<iostream>
using namespace std;

typedef int KeyType;
typedef int InfoType;

//�����������Ķ�������洢��ʾ
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

ElemType e;    //�½����e�Դ��������ֵ

//������������ T �в����ڹؼ��ֵ��� e.key ������Ԫ���ǣ�������Ԫ��
void InsertBST(BSTree *&T, ElemType e)
{
	if (!T)
	{//�����ҵ�����λ�õ��������ʱ�����һ�ν��еݹ����
		BSTNode * S = new BSTNode;      //�����½ڵ� *S
		S->data = e;                                      //�½ڵ� *S ����������Ϊ e
		S->lchild = S->rchild = NULL;       //�½ڵ� *S ��ΪҶ�ӽڵ�
		T = S;                                                  //���½ڵ� *S ���ӵ����ҵ��Ĳ���λ��
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);                   //�� *S ����������
	else if (e.key > T->data.key)
		InsertBST(T->rchild, e);                  //�� *S ����������
}

void CreatBST(BSTree *&T)
{
	T = NULL;
	cout << "��������Ҫ�����ֵ��-1����" << endl;
	cin >> e.key;
	while (e.key  != EOF)
	{
		InsertBST(T, e);
		cout << "�����������Ҫ�����ֵ��-1����" << endl;
		cin >> e.key;
	} 
	cout << "��������������" << endl << endl;
}

//�������
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
		cout << "û�н���������" << endl;
	else
	{
		cout << "����������" << endl;
		InOrderTraversal(T);
	}

	cout << endl;
	system("pause");
}