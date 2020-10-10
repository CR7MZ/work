#include <iostream>
#include <string>
using namespace std;

//题目：https://leetcode-cn.com/problems/longest-palindromic-substring/

//暴力解决法：遍历所有可能的结果，求每一个子串时间复杂度是O(N^2), 判断子串是不是回文O(N)，
//            两者是相乘关系，所以时间复杂度为O(N^3)。 
string longestPalindrome1(string &s)
{
	int len = s.size();                  //字符串长度
	int maxlen = 1;                      //最长回文字符串长度
	int start = 0;                       //最长回文字符串起始地址
	for (int i = 0; i < len; i++)         //起始地址
	{
		for (int j = i + 1; j < len; j++) //结束地址
		{
			int tmp1 = i, tmp2 = j;
			while (tmp1 < tmp2 && s.at(tmp1) == s.at(tmp2))//判断是不是回文
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

//中心扩展法：把给定的字符串的每一个字符作为中心，向两边扩展，这样来找到最长的回文串。时间复杂度为O(N^2)
//            需要注意：1.长度为奇数的回文串2.长度为偶数的回文串，这两种情况
string longestPalindrome2(string s) {
	int max = 1;
	int start = 0;
	for (int i = 0; i < s.size(); i++){                     //求长度为奇数得回文串
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

	for (int i = 0; i < s.size(); i++){                     //求长度为偶数的回文串
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

//动态规划：设状态dp[j][i]表示索j到索引i的子串是否回文，若是，dp[j][i]为1，若不是，dp[j][i]为0。时间复杂度为O(N^2)
//          那么我们要判断dp[j[][i]是否为1，只需要判断dp[j+1][i-1]是否为1（也就是是否为还会问的即可）。
//          状态方程为：dp[j][i] = dp[j+1][i-1], s[j] == s[i]
//                                 0,            s[j] != s[i]

string  longestPalindrome3(string s){
	int n = s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	int max = 1;        //最长回文串的长度
	int start = 0;     //最长回文串的起点
	
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

