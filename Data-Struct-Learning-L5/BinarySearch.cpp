#include<iostream>
#define MAXNUM 30
using namespace std;
typedef int KeyType;
typedef int InfoType;

//构建元素类型
typedef struct
{
	KeyType key;
	InfoType i;
}ElemType;
//构建顺序表类型
typedef struct
{
	ElemType *R;
	int length;
}Table;

//折半查找法
int BinarySearch(Table T, KeyType K, int low, int high)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (K == T.R[mid].key)  //这里出错
			return mid;
		else
			if (K < T.R[mid].key)
				BinarySearch(T, K, low, mid - 1);
			else BinarySearch(T, K, mid + 1, high);
	}
	return 0;
}

void main()
{
	Table T;  //构建顺序表T
	T.R = new ElemType[MAXNUM];  //为顺序表构建空间
	KeyType K;
	cout << "输入即将输入的元素数量（大于8个）" << endl;
	cin >> T.length;
	while (T.length <= 8)
	{
		cout << "小于8个，请重新输入" << endl;
		cin >> T.length;
	}

	cout << "请有序输入元素" << endl;
	for (int i = 1; i <= T.length; i++)
		cin >> T.R[i].key;

	cout << "希望查找的元素为" << endl;
	cin >> K;

	int low = 1; 
	int high = T.length; 
	int result;
	result = BinarySearch(T, K, low, high);   //调用函数
	if (result == 0)
		cout << "希望查找的元素不在此数组内" << endl;
	else cout << "该元素的下标为：" << result << endl;
	system("pause");
}
