class Solution {
    vector<string> ans;
public:
    void permute(int index, string S){
        if(index == S.length()){
            ans.push_back(S);
            return;
        }
        
        permute(index+1, S);
        if(isalpha(S[index])){
            S[index] ^= 1 << 5;
            permute(index+1, S);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        permute(0, S);
        return ans;
    }
};