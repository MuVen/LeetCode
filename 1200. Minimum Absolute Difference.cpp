class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        unordered_map<int, vector<vector<int>>> map;
        
        sort(arr.begin(), arr.end());
        int minD = INT_MAX;
        for(int i = 0; i < arr.size()-1; i++){
            minD = min(minD, arr[i+1]-arr[i]);
        }
            
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i+1]-arr[i] == minD)
                res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};