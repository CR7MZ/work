#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//��Ŀ��https://leetcode-cn.com/problems/count-binary-substrings/

//˼·��
//ͳ��������1��0�ֱ��ж��ٸ�����ͳ�Ƴ���һ������ÿ����������֮���ҳ���Сֵ������������Ϊ���մ𰸡�
//���磺111100011000 ���õ�4323����4323�������������������У�ȡ����Сֵ��������Ϊ3+2+2 = 7��
int countBinarySubstrings(string s) {
	vector<int> v;
	int sum = 1;
	//ͳ�Ƴ�������1��0����
	auto it = s.begin() + 1;
	while (it != s.end()){
		if (*it == *(it - 1)){
			++sum;
		}
		else {
			v.push_back(sum);
			sum = 1;

		}
		it++;
	}
	v.push_back(sum);

	//ȡ�����������������ֵ���Сֵ��ӡ�
	sum = 0;
	for (int i = 0; i < v.size() - 1; i++){
		sum += min(v[i], v[i + 1]);
	}
	return sum;
}


//����˼·��
	//��last��¼ǰ�����ֳ��ֵĴ�����cur��¼�������ֳ��ֵĴ�������last>curʱ��res++��
int countBinarySubstrings(string s) {
	int last, cur, res; last = res = 0; cur = 1;
	for (int i = 1; i<s.size(); i++){
		if (s[i] == s[i - 1]) cur++;
		else{ last = cur; cur = 1; }
		if (last >= cur) res++;
	}
	return res;
}
