#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int  result = stack2.top();
		stack2.pop();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return result;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
int main()
{
	  int n = 0;
	  cout << "请输入数量" << endl;
	  cin >> n;
	  Solution s;
	  int m = n;
	  while (n)
		   {
		     int node;
		     cout << "请输入你想输入的数字" << endl;
		     cin >> node;
		     s.push(node);
		     n--;
		   }
	   cout << "你输入的序列" << endl;
	   while (m)
	   {
		   cout << s.pop();
		   m--;
	   }
	   system("pause");
	   return 0;
	 }