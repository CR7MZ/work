//题目：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106?f=discussion
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//思路：
//定义一个栈s来保存pushV从右向左的每个元素。s每压入一个pushV的元素，将这个元素和popV第一个元素进行比较，若相等则删除s栈顶，进行popV下一个元素的比较
//若不相等，继续压入pushV的元素。若pushV中的元素已经全部压入到栈中，但此时s中仍有元素，并且栈顶元素和此时popV中第一个元素不相等。说明不是。
	bool IsPopOrder(vector<int>pushV, vector<int>popV)
	{
		stack<int> s;
		size_t outindex = 0;//popV下标
		size_t inindex = 0;//pushV下标
		while (outindex<popV.size())
		{
			while (s.empty() || s.top() != popV[outindex])//当栈为空，或者栈顶元素和弹出序列第一个元素不相等时，压栈。
			{
				if (inindex < pushV.size())//在输入序列的范围内压栈。
					s.push(pushV[inindex++]);
				else
					return false;//如果栈不为空且栈顶元素和相对弹出序列元素不相等时，以及输入序列已经压栈完时，则不是弹出序列。
			}
			s.pop();//当栈顶元素和弹出序列的相对元素相等时，删除栈顶，比较栈下一个元素。
			outindex++;//找到弹出序列下一个元素。
		}
		return true;
	}
