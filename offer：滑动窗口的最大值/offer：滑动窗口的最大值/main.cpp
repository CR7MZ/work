#include <iostream>
#include <vector>
using namespace std;

//��Ŀ��https://www.nowcoder.com/questionTerminal/1624bc35a45c42c0bc17d17fa0cba788?f=discussion&toCommentId=6416068

//��Ŀ������
//�ȸ���һ����ȡ���������ֵ���±�ĺ���Func����������ָ��left��rightģ�ⴰ�ڡ�
//1.�����indexΪ - 1ʱ���ҳ���һ�����������ֵ���������±��¼����������index�У���������ƶ���
//2.�����ţ���Ϊ�ƶ���index�п��ܲ��ڳ����У���ʱ��������ۣ�
//1.���index�ڴ����У���ôֻ��Ҫ�ж��¼��봰�ڵ�ֵ��Ҳ���Ǵ�ʱrightָ���ֵ�Ƿ����index�� ָ���ֵ��������ڣ������index������index���䡣
//2.���index���ڴ����У���ô����ȥ����Func��ȡ�µ����ֵ���Լ�index��
class Solution {
public:
	int maxNum(const vector<int>& v, int left, int right)
	{
		int index = -1;
		int max = 0;
		for (int i = left; i <= right; i++){
			if (v[i] > max){
				index = i;
				max = v[i];
			}
		}
		return index;
	}
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> Maxes;
		int index = -1;
		int left = 0;
		int right = left + size - 1;
		while (right < num.size()){
			if (index == -1){
				index = maxNum(num, left, right);
				Maxes.push_back(num[index]);
			}
			else if (index >= left && index <= right){
				if (num[index] > num[right]){
					Maxes.push_back(num[index]);
				}
				else {
					index = right;
					Maxes.push_back(num[index]);
				}
			}
			else {
				index = maxNum(num, left, right);
				Maxes.push_back(num[index]);
			}
			++left;
			++right;
		}
		return Maxes;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector <int> res = s.maxInWindows(v,3);
	for (auto e : res){
		cout << e << endl;
	}
	system("pause");
	return 0;
}