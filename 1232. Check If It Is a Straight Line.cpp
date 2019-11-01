class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 0)
            return false;

        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        int ycoeff = (x2-x1);
        int xcoeff = (y2-y1) * -1;
        int k = ycoeff * y1 + xcoeff * x1;

        for(int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if( ((ycoeff * y) + (xcoeff * x)) != k )
                return false;
        }

        return true;
    }
};