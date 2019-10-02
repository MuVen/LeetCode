#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
	vector<int> vc;
	vector<int> cache;
public:
	int getmin(int top){
		if (top < 0)
			return 0;
		if (top == 0)
			return vc[0];
		if (cache[top] != -1)
			return cache[top];
		int val = top == vc.size() ? 0 : vc[top];
		int m1 = val + getmin(top - 1);
		int m2 = val + getmin(top - 2);
		return cache[top] = MIN(m1, m2);
	}

	int minCostClimbingStairs(vector<int>& cost) {
		vc = move(cost);
		cache.resize(vc.size()+1, -1);
		return getmin(vc.size());
	}
};