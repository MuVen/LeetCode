class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return "";
        
        if(len == 1)
            return to_string(nums[0]);
        
        if(len == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string ans = to_string(nums[0])+"/(";
        for(int i = 1; i < len-1; i++){
            ans += to_string(nums[i])+"/";
        }
        ans += to_string(nums[len-1])+")";
        return ans;
    }
};