class Solution {
public:
    
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int size = points.size();
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                for(int k = j + 1; k < size; k++){
                    double p1x = points[i][0], p1y = points[i][1];
                    double p2x = points[j][0], p2y = points[j][1];
                    double p3x = points[k][0], p3y = points[k][1];
                    double tarea = abs((p1x*(p2y-p3y)) + (p2x*(p3y-p1y)) + (p3x*(p1y-p2y))) / 2;
                    ans = max(ans, tarea);
                }
            }
        }
        return ans;
    }
};