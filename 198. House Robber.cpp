#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		int ppmax, pmax, cmax;
		ppmax = pmax = cmax = 0;

		for (int i = 0; i < n; i++){
			cmax = MAX(pmax, nums[i] + ppmax);
			ppmax = pmax;
			pmax = cmax;
		}
		return cmax;
	}
};