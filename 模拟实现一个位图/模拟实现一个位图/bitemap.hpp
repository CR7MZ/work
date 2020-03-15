#pragma once 
#include <vector>

namespace My
{
	template <size_t N>
	class bitemap
	{
	public:
		bitemap()
			:_bite(( N >> 3 )+1)
		{}

		size_t Size()const 
		{
			return N;
		}

		void set(size_t n)
		{
			if (n > N)
				return;
			size_t index = n / 8;
			size_t pos = n % 8;

			_bite[index] |= (1 << pos);

		}

		void reset(size_t n)
		{
			if (n > N)
				return;
			size_t index = n / 8;
			size_t pos = n % 8;
			_bite[index] &= ~(1 << pos);

		}

		bool test(size_t n)
		{
			if (n > N)
				return false;
			size_t index = n / 8;
			size_t pos = n % 8;

			return 0 != (_bite[index] & (1 << pos));
		}
		size_t count()const //为位图中比特位为1的个数
		{
			int bitCnttable[256] = {
				0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
				3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
				3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
				4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
				3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
				6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
				4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
				6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
				3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
				4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
				6, 7, 6, 7, 7, 8 };

			int count = 0;
			for (size_t i = 0; i < _bite.size(); i++)
			{
				count += bitCnttable[_bite[i]];
			}
			return count;
		}
	private:
		std::vector<char> _bite;
		size_t _bitecount;
	};
}

