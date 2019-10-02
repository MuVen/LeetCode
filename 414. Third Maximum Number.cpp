#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long long int fmax = LLONG_MIN, smax = LLONG_MIN, tmax = LLONG_MIN;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] == fmax || nums[i] == smax || nums[i] == tmax)
				continue;

			if (nums[i] > fmax){
				tmax = smax;
				smax = fmax;
				fmax = nums[i];
			}
			else if (nums[i] > smax){
				tmax = smax;
				smax = nums[i];
			}
			else if (nums[i] > tmax){
				tmax = nums[i];
			}
		}

		if (tmax != LLONG_MIN)
			return tmax;
		
		return MAX(fmax,smax);
	}
};