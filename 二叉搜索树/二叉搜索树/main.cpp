#include<iostream>
using namespace std;
template<class T>
struct BSTNode
{
	BSTNode(const T& data)
		:left(nullptr)
		, right(nullptr)
		, _data(data)
	{}
	BSTNode<T>* left;
	BSTNode<T>* right;
	T _data;
};

template<class T>
class BStree
{
	typedef BSTNode<T> node;
public:
	BStree()
		:_root(nullptr)
	{}
	//插入
	//插入分为两种情况：
	//1.如果树为空，则直接插入根节点中即可
	//2.如果树非空，找到待插入节点，即可
	bool Insert(const T& data)
	{
		if (nullptr == _root)//如果树为空，直接插入到根节点即可
		{
			_root = new node(data);
			return true;
		}

		//树非空
		//找待插入节点在树中的位置，根据二叉搜索树的性质从根节点开始。
		node* cur = _root;
		node* parent = nullptr;//因为待插入节点一定在空指针域，所以就需要定义一个parent节点来找到待插入节点的位置
		while (cur)		        //找到某个新节点的位置一定是，某个节点的空指针域位置。所以当cur为空，说明找到，退出循环。
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->left;
			else if (data>cur->_data)
				cur = cur->right;
			else                 //如果data与cur中值相同，说明有节点插入失败。
				return false;
		}

		//插入新的节点
		cur = new node(data);
		if (data < parent->_data)//如果data小于此时parent中的值，则是parent的左子树
			parent->left = cur;
		else                    //如果data小于此时parent中的值，则是parent的左子树
			parent->right = cur;
		return true;
	}

	//二叉搜索树的删除
	//首先要看树中有没有待删除节点，如果没有则退出即可。
	//如果有，则分为以下四种情况：
	//1.待删除节点无孩子（可直接删除）
	//2.待删除节点只有左孩子（可直接删除）
	//3.待删除节点只有右孩子（可直接删除）
	//4.待删除节点有所左右孩子（不可直接删除）
	bool Delete(const T& data)
	{
		if (nullptr == _root)
			return false;
		//找到待删除节点
		node* cur = _root;
		node* parent = nullptr;//此节点用来删除待删除节点cur。
		while (cur)
		{
			if (cur->_data == data)
				break;
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				parent = cur;
				cur = cur->right;
			}
		}

		if (nullptr == cur)
			return false;

		//删除
		node* delnode = cur;
		//可能没有孩子节点||只有右孩子
		if (cur->left == nullptr)
		{
			if (parent == nullptr)//说明cur是根节点
				_root = cur->right;//因为根节点最后要删除，所以将根节点换为根节点的右子树
			else
			{
				if (parent->left == cur)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
		}
		//只有左孩子
		else if (nullptr==cur->right)
		{
			if (parent == nullptr)//说明cur是根节点
				_root = cur->left;//因为根节点最后要删除，所以将根节点换为根节点的左子树
			else
			{
				if (parent->left == cur)//如果待删除节点cur为其父节点的左子树
					parent->left = cur->left;
				else                    //如果待删除节点cur为其父节点的右子树
					parent->right = cur->left;
			}
		}
		else
		{
			//左右子数都存在
			//在cur的右子树中找到一个代替cur的节点（是cur右子树中最小的节点）。
			//将替代节点中的元素给待删除节点，最后删除替代节点即可。
			node* Del = cur->right;
			parent = cur;
			while (Del->left)
			{
				parent = Del;
				Del = Del->left;
			}
			cur->_data = Del->_data;//将待删除节点中的元素给代替节点Del。

			//删除代替节点Del
			if (Del == parent->left)
				parent->left=Del->right;
			else
				parent->right = Del->right;

			delnode = Del;
		}

		delete delnode;
		return true;
	}

	void Inorder()//中序遍历,验证是否为二叉搜索树
	{
		_Inorder(_root);
	}

	int Leftmin()//最小的数
	{
		if (_root == nullptr)
			return -1;
		node* cur = _root;
		while (cur->left)
		{
			cur = cur->left;
		}
		return cur->_data;
	}

	int RightMax()//最大的数
	{
		if (_root == nullptr)
			return -1;
		node* cur = _root;
		while (cur->right)
		{
			cur = cur->right;
		}
		return cur->_data;
	}
private:
	void _Inorder(node* root)//中序遍历
	{
		if (root)
		{
			_Inorder(root->left);
			cout << root->_data<<" ";
			_Inorder(root->right);
		}
	}
private:
	node* _root;
};
int main()
{
	BStree<int> b;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
		b.Insert(e);

	b.Inorder();
	cout << endl;
	cout << b.Leftmin()<< endl;
	cout << b.RightMax()<< endl;

	b.Delete(0);
	b.Inorder();
	cout << endl;
	cout << b.Leftmin() << endl;
	cout << b.RightMax() << endl;
	system("pause");
	return 0;
}