//��Ŀ��https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba?f=discussion
#include<iostream>
#include<vector>
using namespace std;
//��Ϊ��ת֮���������Ի���Ϊ��������������У���ǰ���������Ĵ�Сһ�������ں���������Ĵ�С����ʱ���ǿ��Է�����С�����־�������������ķֽ���
//��Ϊ����������൱������ģ��������ǿ������ö��ֲ������ҵ���С�����֡�
//1.������ָ��left��right�ֱ�ָ������ĵ�һ��Ԫ�أ������һ��Ԫ�ء�
//2.�ҵ��м��Ԫ�أ����м��Ԫ�ش��ڵ�һ��Ԫ�أ�˵���м��Ԫ��λ��ǰ��ĵ��������飬��ʱ��СԪ��һ��λ���м�Ԫ�صĺ��档���ǿ�����leftָ���м��Ԫ�ء�
//���м�Ԫ��С�ڵ�һ��Ԫ�أ�˵���м��Ԫ��λ�ں���ĵ��������飬��ʱ��СԪ��һ��λ���м�Ԫ�ص�ǰ�档���ǿ�����rightָ���м��Ԫ�ء�

//���������˼·��left��Զָ��ǰ���������е�Ԫ�أ�right��Զָ������������е�Ԫ�ء�����left��ָ��ǰ���������һ��Ԫ�أ�right��ָ�ں��������һ��Ԫ�ء�
//Ҳ���������������ڣ���ʱrightǡ������С��Ԫ�ء��������right-1����left��˵��rightָ����С��Ԫ�ء�
//������Ŀָ�� ����������ظ������֣�Ҳ����˵���ֿ���Ϊ{1��0,1,1,1,1}�������������ж��м�Ԫ����ǰ����������Ǻ��������飬�Ӷ��޷��ҳ����������ֻ�ܱ���Ѱ����Сֵ��
//������Ŀ����ȫ����ɡ�
int minNumberInRotateArray(vector<int> rotateArray) {
	int size = rotateArray.size();
	int left = 0, right = size - 1;
	int mid = 0;
	while (rotateArray[left] >= rotateArray[right])//ȷ��������ת
	{
		if (left == right - 1)//˵�����ڣ��ó���Сֵ���±�
		{
			mid = right;
			break;
		}

		mid = left + (right - left) / 2;
		if (rotateArray[mid] == rotateArray[left] && rotateArray[mid] == rotateArray[right])//���������ͬ���޷�ȷ���м�Ԫ����ǰ����������Ǻ��������飬�ñ�������
			return Func(rotateArray, left, right);
		if (rotateArray[mid] >= rotateArray[left])//�м�Ԫ��λ��ǰ����������飬��ʱ��СԪ�����м�Ԫ�غ��档
			left = mid;
		else                                      //�м�Ԫ��λ�ں�����������飬��ʱ��СԪ�����м�Ԫ��ǰ�档
			right = mid;
	}
	return rotateArray[mid];
}
int Func(vector<int>& v, int left, int right)
{
	int res = v[left];
	for (int i = left + 1; i<right; i++)
	{
		if (v[i]<res)
			res = v[i];
	}
	return res;
}
int main()
{

}