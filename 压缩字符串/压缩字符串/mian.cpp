//题目：https://leetcode-cn.com/problems/string-compression/solution/
#include<iostream>
#include<vector>
#include<string>
//思路：标记两个下标，start和end，如果此时下标对应的两个字符相等，则end向后走。直到不相等，用end减去start计数，将字符放进字符数组中
//接着，如果计数不等于1，则将数字写入到字符数组中。接着更新start到end当前的位置，继续上述操作。
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
				data.push_back((count % 10) + '0');//因为数有可能是高位，且题目要求每个元素长度为1，所以一个一个放进去。
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