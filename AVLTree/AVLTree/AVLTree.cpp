//#include"AVLTree.h"
//int main()
//{
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	AVLTree<int, int> av;
//	for (auto e : a)
//	{
//		//手动写断点
//		if (e == 7)
//		{
//			int x = 0;
//		}
//		av.Insert(make_pair(e, e));
//		cout << "Insert:" << e << "->" << av.IsBalance() << endl;
//	}
//	return 0;
//}


//#include"AVLTree.h"
//#include<vector>
//int main()
//{
//	const int N = 100000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (int i = 0; i < N; i++)
//	{
//		v.push_back(rand());
//	}
//	AVLTree<int, int> av;
//	for (auto e : v)
//	{
//		//手动写断点
//		if (e == 7)
//		{
//			int x = 0;
//		}
//		av.Insert(make_pair(e, e));
//		//cout << "Insert:" << e << "->" << av.IsBalance() << endl;
//	}
//	cout << av.IsBalance() << endl;
//	return 0;
//}


#include"AVLTree.h"
int main()
{
	//int arr[] = { 5,3,7,1,4,6,8,0,2,9 };
	int arr[] = { 90,30,100,20,60,95,105,10,23,40,65 };
	AVLTree<int, int> av;
	for (auto e : arr)
	{
		av.Insert(make_pair(e, e));
		cout << e << " ";
	}
	av.Insert(make_pair(35, 35));
	//av.Insert(make_pair(10, 10));
	cout << endl;
	return 0;
}