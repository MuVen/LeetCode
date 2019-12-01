class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int minRightArray = INT_MAX, maxLeftArray = INT_MIN;
        int leftMostProper = nums.size(), rightMostProper = -1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > minRightArray)
                leftMostProper = i - 1;
            minRightArray = min(minRightArray, nums[i]);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < maxLeftArray)
                rightMostProper = i + 1;
            maxLeftArray = max(maxLeftArray, nums[i]);
        }
        
        return max(rightMostProper - leftMostProper - 1, 0);
    }
};