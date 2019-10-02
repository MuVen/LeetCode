#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int curr_max = nums[0], max_so_far = nums[0];
        for(int i = 1; i < size; i++){
            curr_max = MAX(nums[i], curr_max+nums[i])            ;
            max_so_far = MAX(curr_max, max_so_far);
        }
        return max_so_far;
    }
};