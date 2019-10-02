class Solution {
	int row, col;
	vector<vector<int>> grid;
	vector<vector<int>> res;
public:
	bool isValid(int& x, int& y) {
		if (x >= 0 && x < row && y >= 0 && y < col)
			return true;
		return false;
	}
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		grid = move(M);

		int x[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
		int y[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
		row = grid.size();
		if (row == 0)
			return res;

		col = grid[0].size();

		res.resize(row, vector<int>(col, 0));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				int value = grid[i][j];
				int count = 1;
				for (int k = 0; k < 8; k++) {
					int nx = i + x[k];
					int ny = j + y[k];
					if (isValid(nx, ny)) {
						value += grid[nx][ny];
						count++;
					}
				}

				res[i][j] = value / count;
			}
		}

		return move(res);
	}
};