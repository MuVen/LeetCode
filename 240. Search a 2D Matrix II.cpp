class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        if(row < 0)
            return false;
        
        int col = matrix[0].size()-1;
        if(col < 0)
            return false;
        int srow = 0;
        int scol = col;
        while(1){
            if(srow > row || scol < 0)
                break;
            if(target == matrix[srow][scol])
                return true;
            else if(target > matrix[srow][scol]){
                srow++;
            }else {
                scol--;
            }
        }
        
        return false;
    }
};