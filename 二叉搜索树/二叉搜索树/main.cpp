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
	//����
	//�����Ϊ���������
	//1.�����Ϊ�գ���ֱ�Ӳ�����ڵ��м���
	//2.������ǿգ��ҵ�������ڵ㣬����
	bool Insert(const T& data)
	{
		if (nullptr == _root)//�����Ϊ�գ�ֱ�Ӳ��뵽���ڵ㼴��
		{
			_root = new node(data);
			return true;
		}

		//���ǿ�
		//�Ҵ�����ڵ������е�λ�ã����ݶ��������������ʴӸ��ڵ㿪ʼ��
		node* cur = _root;
		node* parent = nullptr;//��Ϊ������ڵ�һ���ڿ�ָ�������Ծ���Ҫ����һ��parent�ڵ����ҵ�������ڵ��λ��
		while (cur)		        //�ҵ�ĳ���½ڵ��λ��һ���ǣ�ĳ���ڵ�Ŀ�ָ����λ�á����Ե�curΪ�գ�˵���ҵ����˳�ѭ����
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->left;
			else if (data>cur->_data)
				cur = cur->right;
			else                 //���data��cur��ֵ��ͬ��˵���нڵ����ʧ�ܡ�
				return false;
		}

		//�����µĽڵ�
		cur = new node(data);
		if (data < parent->_data)//���dataС�ڴ�ʱparent�е�ֵ������parent��������
			parent->left = cur;
		else                    //���dataС�ڴ�ʱparent�е�ֵ������parent��������
			parent->right = cur;
		return true;
	}

	//������������ɾ��
	//����Ҫ��������û�д�ɾ���ڵ㣬���û�����˳����ɡ�
	//����У����Ϊ�������������
	//1.��ɾ���ڵ��޺��ӣ���ֱ��ɾ����
	//2.��ɾ���ڵ�ֻ�����ӣ���ֱ��ɾ����
	//3.��ɾ���ڵ�ֻ���Һ��ӣ���ֱ��ɾ����
	//4.��ɾ���ڵ��������Һ��ӣ�����ֱ��ɾ����
	bool Delete(const T& data)
	{
		if (nullptr == _root)
			return false;
		//�ҵ���ɾ���ڵ�
		node* cur = _root;
		node* parent = nullptr;//�˽ڵ�����ɾ����ɾ���ڵ�cur��
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

		//ɾ��
		node* delnode = cur;
		//����û�к��ӽڵ�||ֻ���Һ���
		if (cur->left == nullptr)
		{
			if (parent == nullptr)//˵��cur�Ǹ��ڵ�
				_root = cur->right;//��Ϊ���ڵ����Ҫɾ�������Խ����ڵ㻻Ϊ���ڵ��������
			else
			{
				if (parent->left == cur)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
		}
		//ֻ������
		else if (nullptr==cur->right)
		{
			if (parent == nullptr)//˵��cur�Ǹ��ڵ�
				_root = cur->left;//��Ϊ���ڵ����Ҫɾ�������Խ����ڵ㻻Ϊ���ڵ��������
			else
			{
				if (parent->left == cur)//�����ɾ���ڵ�curΪ�丸�ڵ��������
					parent->left = cur->left;
				else                    //�����ɾ���ڵ�curΪ�丸�ڵ��������
					parent->right = cur->left;
			}
		}
		else
		{
			//��������������
			//��cur�����������ҵ�һ������cur�Ľڵ㣨��cur����������С�Ľڵ㣩��
			//������ڵ��е�Ԫ�ظ���ɾ���ڵ㣬���ɾ������ڵ㼴�ɡ�
			node* Del = cur->right;
			parent = cur;
			while (Del->left)
			{
				parent = Del;
				Del = Del->left;
			}
			cur->_data = Del->_data;//����ɾ���ڵ��е�Ԫ�ظ�����ڵ�Del��

			//ɾ������ڵ�Del
			if (Del == parent->left)
				parent->left=Del->right;
			else
				parent->right = Del->right;

			delnode = Del;
		}

		delete delnode;
		return true;
	}

	void Inorder()//�������,��֤�Ƿ�Ϊ����������
	{
		_Inorder(_root);
	}

	int Leftmin()//��С����
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

	int RightMax()//������
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
	void _Inorder(node* root)//�������
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