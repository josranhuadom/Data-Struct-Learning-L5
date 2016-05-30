#include<iostream>
#define MAXNUM 30
using namespace std;
typedef int KeyType;
typedef int InfoType;

//����Ԫ������
typedef struct
{
	KeyType key;
	InfoType i;
}ElemType;
//����˳�������
typedef struct
{
	ElemType *R;
	int length;
}Table;

//�۰���ҷ�
int BinarySearch(Table T, KeyType K, int low, int high)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (K == T.R[mid].key)  //�������
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
	Table T;  //����˳���T
	T.R = new ElemType[MAXNUM];  //Ϊ˳������ռ�
	KeyType K;
	cout << "���뼴�������Ԫ������������8����" << endl;
	cin >> T.length;
	while (T.length <= 8)
	{
		cout << "С��8��������������" << endl;
		cin >> T.length;
	}

	cout << "����������Ԫ��" << endl;
	for (int i = 1; i <= T.length; i++)
		cin >> T.R[i].key;

	cout << "ϣ�����ҵ�Ԫ��Ϊ" << endl;
	cin >> K;

	int low = 1; 
	int high = T.length; 
	int result;
	result = BinarySearch(T, K, low, high);   //���ú���
	if (result == 0)
		cout << "ϣ�����ҵ�Ԫ�ز��ڴ�������" << endl;
	else cout << "��Ԫ�ص��±�Ϊ��" << result << endl;
	system("pause");
}