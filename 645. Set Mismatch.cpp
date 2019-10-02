class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> n;
        int n1x = 0;
        int n2x = 0;
        int mynu = 0;
        for(int i = 0;i < nums.size(); i++){
            n[nums[i]]++;
            n1x ^= nums[i];
            n2x ^= i;
            if(n[nums[i]] == 2)
                mynu = nums[i];
        }
        n2x ^= nums.size();
        
        
        vector<int> res;
        res.resize(2,0);
        res[0] = mynu;
        res[1] = mynu ^ n1x ^ n2x;
        return move(res);
    }
};