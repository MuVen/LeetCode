class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        while(b){
            carry = a & b;
            a = a ^ b;
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};