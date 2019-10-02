class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ds = s + s;
        ds = ds.substr(1, ds.length()-2);
        return ds.find(s) != -1;
    }
};