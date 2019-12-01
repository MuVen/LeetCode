class Solution {
public:
    int findComplement(int num) {
        int i = num;
        int j = 0;
        while(i){
            i = i >> 1;
            j = j << 1;
            j |= 1;
        }
        return num ^ j;
    }
};