class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		int countSetBits = 0;
		int countIsPrime = 0;
		for (int i = L; i <= R; i++)
		{
			countSetBits = 0;
			int num = i;
			while (num)
			{
				num = num & num - 1;
				countSetBits++;
			}

			if (countSetBits == 2 || countSetBits == 3 || countSetBits == 5 || countSetBits == 7 ||
				countSetBits == 11 || countSetBits == 13 || countSetBits == 17 || countSetBits == 19)
				countIsPrime++;
		}

		return countIsPrime;
	}
};