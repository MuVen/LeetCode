class Solution {
public:
    int balancedStringSplit(string s) {
        int bal = 0;
        int res = 0;
        for(auto ch : s){
            bal += ((ch == 'L') ? 1 : -1);
            if(bal == 0)
                res++;
        }
        return res;
    }
};