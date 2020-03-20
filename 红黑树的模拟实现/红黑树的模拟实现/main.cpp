#include "RBTree.hpp"

int main()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> RB;
	for (auto e : a)
	{
		RB.insert(e);
	}

	if (RB.IsVaildRBTree())
		cout << "Yes!!!" << endl;
	else
		cout << "No!!!" << endl;
	return 0;
}