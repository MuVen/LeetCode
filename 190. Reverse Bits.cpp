class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		vector<int> vec;
		while (n) {
			int d = n & 1;
			vec.push_back(d);
			n = n >> 1;
		}
		if (vec.size() < 32) {
			for (int i = vec.size(); i < 32; i++)
				vec.push_back(0);
		}

		uint32_t num = 0;
		uint32_t mf = 1;
		for (int i = vec.size() - 1, j = 0; i >= 0; i--, j++) {
			num += (1 << j) * vec[i];
		}
		return num;
	}
};