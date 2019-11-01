class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_map<int, int> rmap;
        for(int i : arr)
            map[i]++;
        for(auto it = map.begin(); it != map.end(); ++it){
            if(rmap.find(it->second) != rmap.end())
                return false;
            rmap[it->second] = it->first;
        }
        return true;
    }
};