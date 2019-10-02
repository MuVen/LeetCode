class Solution {
    vector<int> cache;
public:
    int tribonacciUtil(int N){
        if(N == 0 || N == 1)
            return N;
        
        if(N == 2)
            return 1;
        
        if(cache[N] != -1)
            return cache[N];
        
        return cache[N] = tribonacciUtil(N-1) + tribonacciUtil(N-2) + tribonacciUtil(N-3);
    }
    
    int tribonacci(int N) {
         cache.resize(N+1, -1);
        return tribonacciUtil(N);
    }
};