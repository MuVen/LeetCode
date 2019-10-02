class Solution {
public:
    string convertToTitle(int n) {
       string s;
        while(n){
            int r = n % 26;
            if(r == 0){
                s += 'Z';
                n = n/26-1;
                continue;
            }
            s += 'A'+r-1;
            n = n/26;
        }
        reverse(s.begin(), s.end());
        return move(s);
    }
};