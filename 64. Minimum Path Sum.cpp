class Solution {
    vector<vector<int>> mgrid;
    vector<vector<int>> cache;
    int row, col;
public:    
    int process(int x, int y){
        if(!(x >= 0 && x < row && y >= 0 && y < col && mgrid[x][y] != -1))
            return INT_MAX;

        if(x == row - 1 && y == col - 1)
            return mgrid[x][y];
            
        if(cache[x][y] != -1)
            return cache[x][y];
        
        int v1 = process(x+1, y);
        int v2 = process(x, y+1);
        return cache[x][y] = mgrid[x][y] + min(v1, v2);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        mgrid = move(grid);
        row = mgrid.size();
        col = mgrid[0].size();
        cache.resize(row,vector<int>(col, -1));
        return process(0,0);
    }
};