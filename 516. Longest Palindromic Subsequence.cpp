#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
    string str;
    vector<vector<int>> cache;
public:
    int maxLPS(int left, int right){
        if(left == right)
            return 1;
        
        if(cache[left][right] != -1)
            return cache[left][right];
        
        if(left + 1 == right && str[left] == str[right])
            return 2;
        
        if(str[left] == str[right])
            return cache[left][right] = maxLPS(left+1, right-1)+2;
        
        return cache[left][right] = MAX(maxLPS(left+1, right), maxLPS(left, right-1));
    }

    int longestPalindromeSubseq(string s) {
        str = move(s);
        int size = str.length();
        cache.resize(size, vector<int>(size, -1));
        return maxLPS(0, str.length()-1);
    }
};