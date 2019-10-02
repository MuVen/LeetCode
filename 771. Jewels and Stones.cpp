class Solution {
    char jwel[256] = {0};

public:
    int numJewelsInStones(string J, string S) {
        for(int i = 0; J[i] != '\0'; i++){
            jwel[J[i]] = 1;
        }
        int count = 0;
        for(int i = 0; S[i] !='\0'; i++){
            if(jwel[S[i]] == 1)count++;
        }
        return count;
    }
};