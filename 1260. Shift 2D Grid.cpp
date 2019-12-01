class Solution {
    int row, col;
    int size;
    vector<vector<int>> res;
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        row = grid.size();
        col = grid[0].size();
        size = row * col;
        
        res.resize(row, vector<int>(col)); 
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int abs_pos = (i * col + j + k) % size;
                res[abs_pos / col][abs_pos % col] = grid[i][j];
            }
        }

        return move(res);
    }
};
