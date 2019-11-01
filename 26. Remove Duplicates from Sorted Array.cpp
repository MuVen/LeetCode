class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> myset;
        for(auto i : nums)
            myset.insert(i);
        int i = 0;
        for(auto it = myset.begin() ; it != myset.end(); ++it, i++)
            nums[i] = *it;
        return myset.size();
    }
};