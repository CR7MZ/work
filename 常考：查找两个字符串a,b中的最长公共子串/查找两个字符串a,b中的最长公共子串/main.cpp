#include <iostream>
#include <string>
#include <vector>
using namespace std;
//https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506

//��ͨ�汾����С���ַ�������a�У�ÿ�δ�a��ȡ���ַ�����ȥb�в��ҡ�
string Func1(const string& a,const string& b){
	if (a.size() > b.size())//�����ַ����ŵ�a��
		swap(a, b);
	string maxstr;//�洢������Ӵ�
	for (int i = 0; i < a.size(); i++)//��a�б��������ν�ȡ�ַ������ŵ�b����
	{
		for (int j = i; j < a.size(); j++)
		{
			string temp = a.substr(i, j - i + 1);
			if (b.find(temp) == std::string::npos)//�Ҳ���
				break;
			else if (maxstr.size() < temp.size())
				maxstr = temp;
		}
	}
	cout << maxstr << endl;
}

//��̬�滮�汾��
//��ά�����У�ÿ��λ�ô洢���ǣ�ƥ�䵽��ǰ�����ַ������ַ�ƥ�����󳤶ȡ�
void Func2(const string& a, const string& b){
	if (a.size() > b.size())//�����ַ����ŵ�a��
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


