//#include"RBTree.h"
//int main()
//{
//	int a[] = { 4,2,6,1,3,5,15,7,16,14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//		cout << "Insert:" << e << "->" << t.IsBalance() << endl;
//	}
//	return 0;
//}


//随机值判断
//#include"RBTree.h"
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
//	RBTree<int, int> av;
//	for (auto e : v)
//	{
//		av.Insert(make_pair(e, e));
//		//cout << "Insert:" << e << "->" << av.IsBalance() << endl;
//	}
//	cout << av.IsBalance() << endl;
//	return 0;
//}


//对比AVL树和红黑树的高度
#include "RBTree.h"
#include "AVLTree.h"
#include<vector>
int main()
{
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}
	RBTree<int, int> rb;
	for (auto e : v)
	{
		rb.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << av.IsBalance() << endl;
	}
	cout << rb.IsBalance() << endl;
	cout << rb.Height() << endl;
	cout << rb._rotateCount << endl;
	AVLTree<int, int> av;
	for (auto e : v)
	{
		av.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << av.IsBalance() << endl;
	}
	cout << av.IsBalance() << endl;
	cout << av.Height() << endl;
	cout << av._rotateCount << endl;
	return 0;
}