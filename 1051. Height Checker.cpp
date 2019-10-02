class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> res = heights;
        sort(res.begin(), res.end());
        int count = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != res[i])
                count++;
        }
        return count;
    }
};