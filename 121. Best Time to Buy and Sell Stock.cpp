#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
	stack<int> max;
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
        if (size == 0)
			return 0;
		int ans = -1;
		for (int i = size - 1; i >= 0; i--){
			int val = prices[i];
			if (max.empty() == true)
				max.push(val);
			else {
				val >= max.top() ?
					max.push(val) : max.push(max.top());
			}
			ans = MAX(ans, max.top() - prices[i]);
		}

		return ans;
	}
};