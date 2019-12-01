class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int open = 0, close = 0, pos = 0;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '(')open++;
            else if(S[i] == ')')close++;
            
            if(open == close){
                string sub = S.substr(pos, i-pos+1);
                string pans = sub.substr(1, sub.length()-2);
                ans += pans;
                pos = i+1;
                open = close = 0;
            }
        }
        return ans;
    }
};