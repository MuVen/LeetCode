class Solution {
	vector<vector<int>> res;
	vector<vector<int>> vis;
	int row, col, valcol, newcol;
public:

	bool isvalid(int x, int y){
		if (x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1 && res[x][y] == valcol && vis[x][y] == 0)
			return true;
		return false;
	}

	void fill(int sr, int sc){
		if (!isvalid(sr, sc))
			return;

		res[sr][sc] = newcol;
		vis[sr][sc] = 9;

		fill(sr - 1, sc);
		fill(sr + 1, sc);
		fill(sr, sc - 1);
		fill(sr, sc + 1);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		res = move(image);
		row = res.size();
		if (row == 0)
			return vector<vector<int>>{};
		col = res[0].size();
		vis.resize(row, vector<int>(col, 0));
		valcol = res[sr][sc];
		newcol = newColor;
		fill(sr, sc);
		return move(res);
	}
};