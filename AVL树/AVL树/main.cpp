template<class T>
struct AVLtreenode
{
	AVLtreenode(const T& data = T())//T如果是内置类型，T（）为0
		:_data(data)
		, _left(nullptr)//T如果是自定义类型，该类必须提供无参的构造函数
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
		//AVL树为空
		if (nullptr == _root)
		{
			_root = new node(data);
			return true;
		}

		//非空
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
		//插入节点
		cur = new node(data);
		if (data < parent->_data)
			cur = parent->_left;
		else
			cur = parent->_right;

		cur->_parent = parent;

		//更新平衡因子,新增加节点后，其父节点的平衡因子会变化。
		if (cur == parent->_left)
			parent->_bf--;//此处我规定，平衡因子是右子树高度减去左子树的高度。所以当左子树加了节点，父结点平衡因子--。
		else
			parent->_bf++;

		if (parent->_bf == 0)
			return;
		else if (parent->_bf == 1 || parent->_bf == -1)
		{
			cur = parent;
			parent = cur->_parent;
		}
		else
		{
			//parent的平衡因子大于1，说明parent违反了AVL的性质，说明以parent为根节点的树，已经不平衡了。
			//所以需要对这棵树进行旋转，使这棵树平衡。
			if (parent->_bf == 2)
			{
				//说明右子树高
				if (cur->_bf==1)
				RotateL(pParent);
			else
				RotateRL(pParent);
			}
		}
	}
private:
	void RotateR(node* parent);//右单旋
private:
	node* _root;
};