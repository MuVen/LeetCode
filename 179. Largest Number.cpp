class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),[](int a, int b){
            string ab = to_string(a)+to_string(b);
            string ba = to_string(b)+to_string(a);
            return ab > ba;
        });
        
        string ans;
        for(int i = 0; i < nums.size(); i++)
            ans += to_string(nums[i]);
        while(ans[0]=='0')
            ans.erase(ans.begin());
        if(ans=="")
            return "0";
        return ans;
    }
};+--