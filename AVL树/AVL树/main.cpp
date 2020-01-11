template<class T>
struct AVLtreenode
{
	AVLtreenode(const T& data = T())//T������������ͣ�T����Ϊ0
		:_data(data)
		, _left(nullptr)//T������Զ������ͣ���������ṩ�޲εĹ��캯��
		, _right(nullptr)
		, _bf(0)
	{}
	AVLtreenode<T>* _left;
	AVLtreenode<T>* _right;
	AVLtreenode<T>* _parent;
	T _data;
	int _bf;
};

template<class T>
class AVLtree
{
	typedef AVLtreenode<T> node;
public:
	AVLtree()
		:_root(nullptr)
	{}

	bool insert(const T& data)
	{
		//AVL��Ϊ��
		if (nullptr == _root)
		{
			_root = new node(data);
			return true;
		}

		//�ǿ�
		node* cur = _root;
		node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data < cur->_data)
				cur = cur->_right;
			else
				return false;
		}
		//����ڵ�
		cur = new node(data);
		if (data < parent->_data)
			cur = parent->_left;
		else
			cur = parent->_right;

		cur->_parent = parent;

		//����ƽ������,�����ӽڵ���丸�ڵ��ƽ�����ӻ�仯��
		if (cur == parent->_left)
			parent->_bf--;//�˴��ҹ涨��ƽ���������������߶ȼ�ȥ�������ĸ߶ȡ����Ե����������˽ڵ㣬�����ƽ������--��
		else
			parent->_bf++;
	}
private:
	node* _root;
};