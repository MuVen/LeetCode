class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        long long int sum = 0;
        long long int f = 0;
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            f += i * A[i];
        }
        
        long long int ans = LLONG_MIN;
        ans = max(ans, f);
        long long int f1 = 0;
        long long int n = A.size();
        for(int i = 1; i < A.size(); i++){
            f1 = f + sum - (n * A[n-i]); 
            ans = max(ans, f1);
            f = f1;
        }
        return ans;
    }
};