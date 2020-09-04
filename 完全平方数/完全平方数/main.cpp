#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ÌâÄ¿£ºhttps://leetcode-cn.com/problems/perfect-squares/
//½âÎö£ºhttps://blog.csdn.net/zw159357/article/details/82595031?utm_medium=distribute.pc_relevant.none-task-blog-utm_term-1&spm=1001.2101.3001.4242

int numSquares(int n) {
	vector<int> dp(n + 1, 100000);
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		int j = 1;
		while (i - j*j >= 0){
			dp[i] = min(dp[i], dp[i - j*j] + 1);
			j++;
		}
	}
	return dp[n];
}
