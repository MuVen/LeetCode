class Solution {
public:
    static inline bool divide(int n){
        int tn = n;
        while(n){
            int d = n % 10;
            if(d == 0 || tn % d != 0)
                return false;
            n = n/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(divide(i))
                ans.push_back(i);
        }
        return move(ans);
    }
};