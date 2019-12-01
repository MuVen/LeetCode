class Solution {
public:
    /*char findTheDifference(string s, string t) {
        int freq1[26]={0};
        int freq2[26]={0};
        for(auto c : s)
            freq1[c-'a']++;
        for(auto c : t)
            freq2[c-'a']++;
        for(int i = 0; i < 26;i++){
            if(freq1[i] != freq2[i])
                return i+'a';
        }
        return '\0';
    }*/
    char findTheDifference(string s, string t) {
        char ch = 0;
        for(auto c : s)
            ch = ch ^ c;
        for(auto c : t)
            ch = ch ^ c;
        return ch;
    }
};