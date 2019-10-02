class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string ts;
        for(int i = 0; i < s.length(); i++){
            if(i == 0 && s[i] == ' ')
                continue;
            if(i>0 && s[i] == ' ' && s[i-1] == ' ')
                continue;
            if(i > 0 && s[i] == ' ' && s[i-1] != ' '){
                ans.push_back(ts);
                ts.clear();
                continue;
            }
            ts += s[i];
        }
        if(ts != "")
            ans.push_back(ts);
        string anss;
        for(int i = ans.size()-1; i>=0; i--)
            anss += ans[i]+" ";
        
        return anss.substr(0, anss.length()-1);
    }
};