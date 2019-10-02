class Solution {
    vector<int> cache;
public:
    int fibUtil(int N){
        if(N == 0 || N == 1)
            return N;
        
        if(cache[N] != -1)
            return cache[N];
        
        return cache[N] = fibUtil(N-1) + fibUtil(N-2);
    }

    int fib(int N) {
        cache.resize(N+1, -1);
        return fibUtil(N);
    }
};