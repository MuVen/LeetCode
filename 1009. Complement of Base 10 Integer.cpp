class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0)
            return 1;
        
        int num = N;
        int i = 0;
        
        while(N){
            num = num ^ (1<<i++);
            N = N >> 1;
        }

        return num;
    }
};