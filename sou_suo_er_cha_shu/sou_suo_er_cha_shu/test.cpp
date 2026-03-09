#include"BinarySearchTree.h"
void test()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	t.Erase(4);
	t.InOrder();

	t.Erase(6);
	t.InOrder();

	t.Erase(7);
	t.InOrder();

	t.Erase(3);
	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
	}
	t.InOrder();
}
void test1()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}
int main()
{
	test();
	return 0;
}
