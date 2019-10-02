#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        result.resize(2, -1);
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size();i++){
            if(map.find(target-nums[i]) != map.end()){
                result[0] = MIN(i,map[target-nums[i]]);
                result[1] = MAX(i,map[target-nums[i]]);
                return move(result);
            }
            map[nums[i]] = i;
        }
        return move(result);
    }
};