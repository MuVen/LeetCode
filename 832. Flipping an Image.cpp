class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int row = A.size();
		int col = A[0].size();
		if (row == 0)
			return move(A);

		for (int i = 0; i < row; i++){
			int clen = col;
			for (int j = 0; j < clen / 2; j++){
				swap(A[i][j], A[i][clen - j - 1]);
				A[i][j] = A[i][j] ? 0 : 1;
				A[i][clen - j - 1] = A[i][clen - j - 1] ? 0 : 1;
			}
			if (clen % 2 != 0)
				A[i][clen / 2] = A[i][clen / 2] ? 0 : 1;
		}

		return move(A);
	}
};