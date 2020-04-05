//题目：https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49?f=discussion
#include<iostream>
#include<stack>
using namespace std;
//思路：
//定义两个栈，用来放元素的ele,用来记录最小元素的mi。
//1、入栈的时候，需要判定mi是否为空，或者此时入栈的这个元素是否小于或者等于此时mi栈顶元素，若是则同时入mi栈，将最小元素统计起来。
//2、出栈的时候，若此时ele栈顶元素和mi栈顶元素相同，则也需要将mi栈顶元素出栈。若不止这么做，那么ele的最小元素将错误。
class Minstack
{
public:
	void pop()
	{
		if (Min.top() == elem.top())
			Min.pop();
		elem.pop();
	}
	void push(int x)
	{
		elem.push(x);//将正常数据入正常栈。
		if (Min.empty() || x <=Min.top())//如果最小栈中为空，则入最小栈，或者当谁的值X比最小栈的栈顶元素小，入栈。
			Min.push(x);
	}
	int top()
	{
		return elem.top();//数据栈的栈顶
	}
	int min()
	{
		return Min.top();//提取最小栈栈顶元素，为最小值
	}
private:
	stack<int> elem;//放数据的栈
	stack<int> Min;//放最小值的栈
};