class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0)
            return;
        
        int i = 0;
        for(int n = 0; n < nums.size(); n++){
            if(nums[n] != 0){
                swap(nums[n], nums[i++]);
            }
        }
    }
};