#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
	vector<vector<int>> CA;
	vector<vector<int>> cache;
	int rows, cols;
	int ans;
	const int inf = 1e8;
public:

	int go(int x, int y){
		if (x == rows)
			return 0;

		if (y < 0 || y >= cols)
			return inf;

		if (cache[x][y] != -1)
			return cache[x][y];

		int ans = INT_MAX;
		int& cval = CA[x][y];

		//case 1: x+1, y
		ans = MIN(cval + go(x + 1, y), ans);

		//case 2: x+1, y-1
		ans = MIN(cval + go(x + 1, y - 1), ans);

		//case 3: x+1, y+1
		ans = MIN(cval + go(x + 1, y + 1), ans);

		return cache[x][y] = ans;
	}

	int minFallingPathSum(vector<vector<int>>& A) {
		ans = INT_MAX;
		CA = move(A);
		rows = CA.size();
		cols = CA[0].size();

		cache.resize(rows);
		for (int i = 0; i < rows; i++){
			cache[i].resize(cols, -1);
		}
		
		for (int i = 0; i < cols; i++){
			ans = MIN(ans, go(0, i));
		}
		return ans;
	}
};