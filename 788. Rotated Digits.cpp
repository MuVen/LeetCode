class Solution {
public:
    static inline bool isGood(int n){
        int d = 0;
        bool hasFour = false;
        while(n){    
            d = n % 10;
            if(d == 3 || d == 4 || d == 7)
                return false;
            if(d == 2 || d == 5 || d == 6 || d == 9)
                hasFour = true;
            n = n / 10;
        }   
        return hasFour;
    }
    
    int rotatedDigits(int N) {
        int count = 0;
        for(int i = 0; i <= N; i++){
            if(isGood(i))
                count++;
        }
        return count;
    }
};