class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;

		sort(nums.begin(), nums.end());

		int count = 0;
        int prev = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(i == 0 || prev != nums[i]){
                if(binary_search(nums.begin()+i+1, nums.end(), nums[i] + k))
                    count++;
                prev = nums[i];
            }
        }

		return count;
	}
};