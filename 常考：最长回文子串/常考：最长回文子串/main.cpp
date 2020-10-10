#include <iostream>
#include <string>
using namespace std;

//��Ŀ��https://leetcode-cn.com/problems/longest-palindromic-substring/

//������������������п��ܵĽ������ÿһ���Ӵ�ʱ�临�Ӷ���O(N^2), �ж��Ӵ��ǲ��ǻ���O(N)��
//            ��������˹�ϵ������ʱ�临�Ӷ�ΪO(N^3)�� 
string longestPalindrome1(string &s)
{
	int len = s.size();                  //�ַ�������
	int maxlen = 1;                      //������ַ�������
	int start = 0;                       //������ַ�����ʼ��ַ
	for (int i = 0; i < len; i++)         //��ʼ��ַ
	{
		for (int j = i + 1; j < len; j++) //������ַ
		{
			int tmp1 = i, tmp2 = j;
			while (tmp1 < tmp2 && s.at(tmp1) == s.at(tmp2))//�ж��ǲ��ǻ���
			{
				tmp1++;
				tmp2--;
			}

			if (tmp1 >= tmp2 && j - i + 1 > maxlen)
			{
				maxlen = j - i + 1;
				start = i;
			}
		}
	}

	return s.substr(start, maxlen);
}

//������չ�����Ѹ������ַ�����ÿһ���ַ���Ϊ���ģ���������չ���������ҵ���Ļ��Ĵ���ʱ�临�Ӷ�ΪO(N^2)
//            ��Ҫע�⣺1.����Ϊ�����Ļ��Ĵ�2.����Ϊż���Ļ��Ĵ������������
string longestPalindrome2(string s) {
	int max = 1;
	int start = 0;
	for (int i = 0; i < s.size(); i++){                     //�󳤶�Ϊ�����û��Ĵ�
		int j = i - 1, k = i + 1;
		while (j >= 0 && k < s.size() && s[j] == s[k]){
			if (k - j + 1 > max){
				max = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}

	for (int i = 0; i < s.size(); i++){                     //�󳤶�Ϊż���Ļ��Ĵ�
		int j = i, k = i + 1;
		while (j >= 0 && k < s.size() && s[j] == s[k]){
			if (k - j + 1 > max){
				max = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}
	return s.substr(start, max);
}

//��̬�滮����״̬dp[j][i]��ʾ��j������i���Ӵ��Ƿ���ģ����ǣ�dp[j][i]Ϊ1�������ǣ�dp[j][i]Ϊ0��ʱ�临�Ӷ�ΪO(N^2)
//          ��ô����Ҫ�ж�dp[j[][i]�Ƿ�Ϊ1��ֻ��Ҫ�ж�dp[j+1][i-1]�Ƿ�Ϊ1��Ҳ�����Ƿ�Ϊ�����ʵļ��ɣ���
//          ״̬����Ϊ��dp[j][i] = dp[j+1][i-1], s[j] == s[i]
//                                 0,            s[j] != s[i]

string  longestPalindrome3(string s){
	int n = s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	int max = 1;        //����Ĵ��ĳ���
	int start = 0;     //����Ĵ������
	
	for(int i = 0; i < n;i++){
		for(int j = 0; j <= i;j++){
			if(i-j < 2){
				dp[j][i] = (s[i] == s[j]);
			} else {
				dp[j][i] = (s[i] == s[j] && dp[j+1][i-1]);
			}
			
			if(dp[j][i] && i-j+1 > max){
				max = i-j+1;
				start = j;
			}
	}
	return s.substr(start,max);
}

