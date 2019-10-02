class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		vector<int> vec;
		while (N){
			int d = N % 10;
			vec.push_back(d);
			N = N / 10;
		}
		reverse(vec.begin(), vec.end());
		int pos = vec.size();
		for (int i = vec.size() - 2; i >= 0; i--){
			if (vec[i] > vec[i + 1]){
				vec[i]--;
				pos = i + 1;
			}
		}

		for (int i = pos; i < vec.size(); i++)
			vec[i] = 9;

		int num = 0;
		for (int i = 0; i < vec.size(); i++){
			num = num * 10 + vec[i];
		}

		return num;
	}
};