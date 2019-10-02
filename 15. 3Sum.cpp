class Solution {
public:
	bool isunique(vector<int>& nums){
		int val = nums[0];
		for (int i = 1; i < nums.size(); i++)
			if (nums[i] != val)
				return false;
		return true;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		if(nums.size() == 0)
            return vector<vector<int>>{};
        
        vector<vector<int>> result;
		if (isunique(nums)){
			if (nums[0] == 0 && nums.size() >= 3){
				vector<int> v{ 0, 0, 0 };
				result.push_back(v);
				return result;
			}
			else{
				return vector<vector<int>>{};
			}
		}

		set<vector<int>> myset;
		sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size - 2; i++){
			int a = nums[i];
			int left = i + 1;
			int right = size-1;
			while (left < right){
				int b = nums[left];
				int c = nums[right];
				if (a + b + c == 0){
					vector<int> t;
					t.push_back(a);
					t.push_back(b);
					t.push_back(c);
					if(myset.find(t) == myset.end()){
						result.push_back(t);
						myset.insert(t);
					}
					left++;
					right--;
				}
				else if (a + b + c < 0){
					left++;
				}
				else if (a + b + c > 0){
					right--;
				}
			}
		}
		return result;
	}
};
