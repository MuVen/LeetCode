class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        x = abs(x);
        int x1 = 0, xt = x, d = 0;
        while(x){
            d = x % 10;
            if(x1 == INT_MAX/10 && d > INT_MAX%10)
                return false;
            if(x1 > INT_MAX/10)
                return false;
            x1 = x1 * 10 + d;
            x = x / 10;
        }
        return xt == x1;
    }
};