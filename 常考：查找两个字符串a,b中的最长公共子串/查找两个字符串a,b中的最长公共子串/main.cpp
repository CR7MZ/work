#include <iostream>
#include <string>
#include <vector>
using namespace std;
//https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506

//普通版本：将小的字符串换到a中，每次从a中取子字符串，去b中查找。
string Func1(const string& a,const string& b){
	if (a.size() > b.size())//将短字符串放到a中
		swap(a, b);
	string maxstr;//存储最长公共子串
	for (int i = 0; i < a.size(); i++)//从a中遍历，依次截取字符串，放到b中找
	{
		for (int j = i; j < a.size(); j++)
		{
			string temp = a.substr(i, j - i + 1);
			if (b.find(temp) == std::string::npos)//找不到
				break;
			else if (maxstr.size() < temp.size())
				maxstr = temp;
		}
	}
	cout << maxstr << endl;
}

//动态规划版本：
//二维数组中，每个位置存储的是，匹配到当前两个字符串的字符匹配的最大长度。
void Func2(const string& a, const string& b){
	if (a.size() > b.size())//将短字符串放到a中
		swap(a, b);
	int max = 0, start = -1;
	vector<vector<int>> v(a.size() + 1, vector<int>(b.size() + 1, 0));
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
				v[i][j] = v[i - 1][j - 1] + 1;
			if (v[i][j] > max){
				max = v[i][j];
				start = i - max;
			}
		}
	}
	cout << a.substr(start, max) << endl;
}


