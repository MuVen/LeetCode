class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int mans = -1;
        for(auto i : nums){
            if(i == 1){
                count++;
            }else{
                mans = max(count, mans);
                count = 0;
            }
        }
        mans = max(count, mans);
        return mans;
    }
};