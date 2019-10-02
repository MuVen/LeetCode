class Solution {
public:
    string reverseOnlyLetters(string S) {
        string retstr;
        int len = S.length();
        if(len == 0)
            return "";

        retstr.resize(len);
        retstr[len]='\0';

        int i = 0, j = len-1;
        while(i <= j){
            bool fchar = (S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <='Z');
            bool lchar = (S[j] >= 'a' && S[j] <= 'z') || (S[j] >= 'A' && S[j] <='Z');    
            if(fchar == true && lchar == true){
                retstr[i] = S[j];
                retstr[j] = S[i];
                i++;
                j--;
            }else if(fchar == true && lchar == false){
                retstr[j] = S[j];
                j--;
            }else if(fchar == false && lchar == true){
                retstr[i] = S[i];
                i++;
            }else{
                retstr[i] = S[i];
                retstr[j] = S[j];
                i++;
                j--;
            }
        }
        
        return retstr;
    }
};