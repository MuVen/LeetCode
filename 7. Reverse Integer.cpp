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
		//handling the base cases for this question is very important.
		//for INT_MAX or INT_MIN have to return 0;
		//have to handle overflow.
		//if number > INT_MAX/10 then return 0.
		//if number == INT_MAX/10 then if d > INT_MAX%10 then return 0.
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