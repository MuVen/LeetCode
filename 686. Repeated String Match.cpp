class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A.find(B) != string::npos)
            return 1;
        
        string result = A;
        int q = 1;
        for(;result.length() < B.length(); q++){ 
            result += A; 
        }

        if(result.find(B) != string::npos)
            return q;

        result += A;
        if(result.find(B) != string::npos)
            return q+1;

        return -1;
    }
};