//��Ŀ��https://leetcode-cn.com/problems/string-compression/solution/
#include<iostream>
#include<vector>
#include<string>
//˼·����������±꣬start��end�������ʱ�±��Ӧ�������ַ���ȣ���end����ߡ�ֱ������ȣ���end��ȥstart���������ַ��Ž��ַ�������
//���ţ��������������1��������д�뵽�ַ������С����Ÿ���start��end��ǰ��λ�ã���������������
int compress(std::vector<char>& chars) {
	size_t start = 0, end, count, len = 0;
	while (start<chars.size()){
		end = start + 1;
		while (end<chars.size() && chars[end] == chars[start])end++;
		count = end - start;
		chars[len++] = chars[start];
		if (count != 1){
			std::string data;
			while (count>0)
			{
				data.push_back((count % 10) + '0');//��Ϊ���п����Ǹ�λ������ĿҪ��ÿ��Ԫ�س���Ϊ1������һ��һ���Ž�ȥ��
				count /= 10;
			}
			std::reverse(data.begin(), data.end());
			for (auto ch : data){
				chars[len++] = ch;
			}
		}
		start = end;
	}
	return len;
}