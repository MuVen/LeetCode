class Solution {
	vector<int> result;
public:
	vector<int> grayCode(int n) {
		int N = 1<<n;
		for (int i = 0; i < N; i++){
			int val = i ^ (i >> 1);
			result.push_back(val);
		}
		return move(result);
	}
};