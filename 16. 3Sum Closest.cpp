class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX, closeSum = 0;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int i,j,k,sum;
        for(i = 0; i < size-2; i++){
            j = i + 1, k = size-1;
            while(j < k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum == target){
                     return target;
                }else if(sum > target){
                    k--;
                }else{
                    j++;
                }
				/*
					closest sum to the given target. if you find target sum return the same.
					else find the abs diff of target and sum. find the min value of diff and also
					save closest sum to the target as well.
				*/
                int adiff = abs(target-sum);
                if(adiff < ans){
                    ans = adiff;
                    closeSum = sum;
                }
            }
        }
        
        return closeSum;    
    }
};