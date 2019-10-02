class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(len == 1 || len == 0)return;
        char temp;
        for(int i = 0; i < len/2; i++){
            temp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = temp;
        }
    }
};