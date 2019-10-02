class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        string newstr;
        for(int i = 0; i < s.length(); i++){
            if(s[i]>='a'&&s[i]<='z')
                newstr += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                newstr += (s[i]+32);
            }else if(s[i] >= '0' && s[i] <= '9'){
                newstr += s[i];
            }
        }
        
        int slen = newstr.length();
        for(int i = 0; i < slen/2; i++){
            if(newstr[i] != newstr[slen-i-1])
                return false;
        }
        return true;
    }
};