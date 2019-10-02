class Solution {
public:
    int titleToNumber(string s) {
        if(s.length() == 0)
            return 0;
        
        int num = 0;
        for(int i = 0; s[i] != '\0'; i++)
            num = num*26+(s[i]-'A'+1);
        return num;
    }
};