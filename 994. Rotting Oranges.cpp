class Solution {
    vector<vector<bool>> visited;
    int row, col;
    vector<vector<int>> mgrid;
    int xM[4]={-1,0,1,0};
    int yM[4]={0,1,0,-1};
    int ans = 0;
    int rans = INT_MAX;
public:
    bool isValid(int x, int y){
        if(x >= 0 && x < row && y >=0 && y < col && visited[x][y] == false && mgrid[x][y] == 1)
            return true;
        return false;
    }
    
    void process(int x, int y){
        cout<<x<<" "<<y<<" "<<" "<<ans<<endl;
        queue<int> que;
        que.push(x);
        que.push(y);
        que.push(0);
        visited[x][y] = true;
        mgrid[x][y] = 2;
        
        while(!que.empty()){
            int x1 = que.front();que.pop();
            int y1 = que.front();que.pop();
            int l1 = que.front();que.pop();
            ans = max(ans,l1);
            //cout<<x1<<" "<<y1<<" "<<l1<<" "<<ans<<endl;
            for(int i = 0; i < 4 ; i++){
                int nx = x1 + xM[i];
                int ny = y1 + yM[i];
                if(isValid(nx, ny)){
                    que.push(nx);
                    que.push(ny);
                    que.push(l1+1);
                    visited[nx][ny] = true;
                    mgrid[nx][ny] = 2;
                }
            }
        }
        
        
        rans = min(rans, ans);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        
        cout<<row<<" "<<col<<endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]==2){
                    mgrid = grid;
                    visited.resize(row, vector<bool>(col, false));
                    cout<<i<<" "<<j<<endl;
                    process(i,j);
                }
            }
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mgrid[i][j] == 1)
                    return -1;
            }
        }
        
        return rans;
    }
};