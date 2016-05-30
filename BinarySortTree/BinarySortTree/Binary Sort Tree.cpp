typedef int KeyType
typedef int InfoType

typedef struct
{
	KeyType key;
	InfoType otherinfo;
}ElemType;
typedef struct BSTNode//能删掉吗？
{
	ElemType data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

void CreatBST(BSTree &T)
{
	T = NULL;
	cin >> e;
	if(e.key == '#')
		break;
	else
	{
		InsertBST(T, e);
		cin >> e;
	}
}

void InsertBST(BSTree &T, ElemType e)
{
	
}