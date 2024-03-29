class Solution {
public:
    int hammingDistance(int x, int y) {
        int value = x ^ y;
        int count = 0;
        while(value){
            count++;
            value = value & value-1;
        }
        return count;
    }
};