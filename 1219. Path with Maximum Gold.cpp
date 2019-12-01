class Solution {
    vector<vector<int>> mgrid;
    //vector<vector<int>> cache;
    int row, col;
    int maxG = INT_MIN;
public:
    bool isValid(int x, int y){
        if(x >= 0 && x < row && y >= 0 && y < col && mgrid[x][y] != -1 && mgrid[x][y] != 0)
            return true;
        return false;
    }
    
    bool cantMove(int x, int y){
        if(!isValid(x-1,y) && !isValid(x,y+1) && !isValid(x+1, y) && !isValid(x,y-1))
            return true;
        return false;
    }
    
    void process(int x, int y, int sum){
        if(!isValid(x, y))
            return;
        
        //cout<<x<<" "<<y<<endl;
        int temp = mgrid[x][y];
        mgrid[x][y] = -1;
        sum += temp;
        
        if(cantMove(x,y)){
            maxG = max(maxG, sum);
            mgrid[x][y] = temp;
            return;
        }
        
        process(x-1,y,sum);
        process(x,y+1,sum);
        process(x+1,y,sum);
        process(x,y-1,sum);
        
        mgrid[x][y] = temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        mgrid = move(grid);
        row = mgrid.size();
        col = mgrid[0].size();
        //cache.resize(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                process(i,j,0);
        return maxG;
    }
};