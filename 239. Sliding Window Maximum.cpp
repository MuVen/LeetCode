class Solution {
	deque<int> deq;
	vector<int> result;
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); i++){
			if (!deq.empty() && deq.front() == i - k)
				deq.pop_front();

			while (!deq.empty() && nums[i] > nums[deq.back()])
				deq.pop_back();
			
			deq.push_back(i);
			if (i >= k - 1)
				result.push_back(nums[deq.front()]);

		}
		return move(result);
	}
};