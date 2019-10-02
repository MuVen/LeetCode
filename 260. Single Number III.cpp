class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>{};
        
        int val = 0;
        for(int i = 0; i < nums.size(); i++){
            val ^= nums[i];
        }
        
        int sone = (val & ~(val-1));
        int fnum = 0, snum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]&sone)
                fnum ^= nums[i];
            else
                snum ^= nums[i];
        }
        
        vector<int> res;
        res.push_back(fnum);
        res.push_back(snum);
        return move(res);
    }
};