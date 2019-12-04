class Solution {
public:
/*
Since the array is already sorted, we can keep two pointers ii and jj, 
where ii is the slow-runner while jj is the fast-runner. 
As long as nums[i] = nums[j]nums[i]=nums[j], 
we increment jj to skip the duplicate.
When we encounter nums[j] != nums[i]
the duplicate run has ended so we must copy its value to nums[i + 1].
i is then incremented and we repeat the same process again until jj reaches the end of array.
*/
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
			return nums.size();
	
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }
        
        return i+1;
	}
};
/*
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
*/