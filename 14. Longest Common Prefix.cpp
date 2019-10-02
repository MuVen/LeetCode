#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {   
        if(strs.size() == 0) return "";
        
        int min = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].length();
            min = MIN(min, len);
        }

        int k;
        string s1, s2;

        for(int i = 0; i < strs.size() - 1; i++){
            s1 = strs[i];
            s2 = strs[i+1];
            for(k = 0; k < min; k++){
                if(s1[k] != s2[k]) 
                    break;
            }

            if(k < min)
                min = k;
            
            if(min == 0) return "";
        }
        
        return min == 0 ? "" : strs[0].substr(0, min);
    }
};