//��Ŀ��https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106?f=discussion
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//˼·��
//����һ��ջs������pushV���������ÿ��Ԫ�ء�sÿѹ��һ��pushV��Ԫ�أ������Ԫ�غ�popV��һ��Ԫ�ؽ��бȽϣ��������ɾ��sջ��������popV��һ��Ԫ�صıȽ�
//������ȣ�����ѹ��pushV��Ԫ�ء���pushV�е�Ԫ���Ѿ�ȫ��ѹ�뵽ջ�У�����ʱs������Ԫ�أ�����ջ��Ԫ�غʹ�ʱpopV�е�һ��Ԫ�ز���ȡ�˵�����ǡ�
	bool IsPopOrder(vector<int>pushV, vector<int>popV)
	{
		stack<int> s;
		size_t outindex = 0;//popV�±�
		size_t inindex = 0;//pushV�±�
		while (outindex<popV.size())
		{
			while (s.empty() || s.top() != popV[outindex])//��ջΪ�գ�����ջ��Ԫ�غ͵������е�һ��Ԫ�ز����ʱ��ѹջ��
			{
				if (inindex < pushV.size())//���������еķ�Χ��ѹջ��
					s.push(pushV[inindex++]);
				else
					return false;//���ջ��Ϊ����ջ��Ԫ�غ���Ե�������Ԫ�ز����ʱ���Լ����������Ѿ�ѹջ��ʱ�����ǵ������С�
			}
			s.pop();//��ջ��Ԫ�غ͵������е����Ԫ�����ʱ��ɾ��ջ�����Ƚ�ջ��һ��Ԫ�ء�
			outindex++;//�ҵ�����������һ��Ԫ�ء�
		}
		return true;
	}
