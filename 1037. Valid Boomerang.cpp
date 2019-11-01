class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {      
        int yadiff = points[1][1]-points[0][1];
        int xadiff = points[1][0]-points[0][0];
        
        int ybdiff = points[2][1]-points[1][1];
        int xbdiff = points[2][0]-points[1][0];
        
        return !(yadiff*xbdiff == ybdiff*xadiff); 
    }
};