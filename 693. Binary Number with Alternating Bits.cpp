class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cur = n % 2;
        n = n / 2;
        while(n){
            if(cur == n%2)
                return false;
            cur = n%2;
            n = n/2;
        }
        return true;
    }
};