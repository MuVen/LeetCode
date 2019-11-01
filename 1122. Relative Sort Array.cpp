class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mymap;
        for(int i : arr1)
            mymap[i]++;
        
        vector<int> result;
        for(int i : arr2){
            int c = mymap[i];
            while(c--)
                result.push_back(i);
            mymap.erase(i);
        }
        
        vector<int> remaining;
        for(auto it = mymap.begin(); it != mymap.end(); ++it){
            int c = it->second;
            while(c--)
                result.push_back(it->first);
        }
        
        return result;
    }
};