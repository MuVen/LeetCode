class Solution {
public:
	int gcd(int a, int b){
		if (a == 0)
			return b;

		return gcd(b%a, a);
	}

	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0 || k == 0)
			return;

		int size = nums.size();

		if (size == 1)
			return;

		int count = gcd(k, size);
		int j, temp, ti;
		for (int i = 0, ti = size - 1; i < count; i++, ti--){
			j = ti;
			temp = nums[j];
			while (1){
				int val = (j - k);
				while (val < 0)
					val = size + val;
				if (val == ti)
					break;
				nums[j] = nums[val];
				j = val;
			}
			nums[j] = temp;
		}
	}
};