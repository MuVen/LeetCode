class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return 0;
        if(x == INT_MIN)
            return 0;
        if(x == INT_MAX)
            return 0;
		bool isnegative = x < 0;
		if (isnegative)
			x = x * -1;
		vector<int> vec;
		while (x) {
			vec.push_back(x % 10);
			x = x / 10;
		}
		int oflow = INT_MAX / 10;
		int mdigit = isnegative ? 8 : 7;
		int num = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (num > oflow)
				return 0;
			else if (num == oflow) {
				if (vec[i] > mdigit)
					return 0;
			}
			num = num * 10 + vec[i];
		}
		return isnegative ? num * -1 : num;
	}
};