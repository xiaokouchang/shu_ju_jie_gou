#include"BinarySearchTree.h"
using namespace key_value;
//void test()
//{
//	int a[] = { 8,3,1,10,6,4,7,14,13 };
//	BSTree<int> t;
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//	t.InOrder();
//
//	t.Erase(4);
//	t.InOrder();
//
//	t.Erase(6);
//	t.InOrder();
//
//	t.Erase(7);
//	t.InOrder();
//
//	t.Erase(3);
//	t.InOrder();
//
//	for (auto e : a)
//	{
//		t.Erase(e);
//	}
//	t.InOrder();
//}
//void test1()
//{
//	int a[] = { 8,3,1,10,6,4,7,14,13 };
//	BSTree<int> t;
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//	t.InOrder();
//}
void test1()
{
	//BSTree<string, Date> carTree;
	BSTree<string, string> dict;
	dict.InsertR("insert", "插入");
	dict.InsertR("sort", "排序");
	dict.InsertR("right", "右边");
	dict.InsertR("date", "日期");
	string str;
	while (cin >> str)
	{
		BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret)
		{
			cout << ret->_value << endl;
		}
		else
		{
			cout << "没有这个单词" << endl;
		}
	}
}
void test2()
{
	//统计水果出现的次数
	string arr[] = { "苹果","西瓜","苹果","西瓜","苹果","苹果","西瓜","苹果","香蕉" };
	BSTree<string, int> countTree;
	for (auto& str : arr)
	{
		auto ret = countTree.FindR(str);
		if(ret == nullptr)
		{
			countTree.InsertR(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}
int main()
{
	//test1();
	test2();
	return 0;
}
