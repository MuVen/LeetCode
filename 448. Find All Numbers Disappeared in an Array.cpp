#define ABS(x) ((x)<(0)?(-x):(x))

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>{};
 
        for(int i = 0; i < nums.size(); i++){
            int index = ABS(nums[i])-1;
            nums[index] = nums[index] > 0 ? nums[index]*-1 : nums[index];
        }
        
        vector<int> res;
        for(int i =0; i < nums.size();i++){
            if(nums[i]>0)
                res.push_back(i+1);
        }
        
        return move(res);
    }
};