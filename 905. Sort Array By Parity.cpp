class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() == 0)
            return vector<int>{};
        
        //QuickSort Logic
        int sIndex = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i]%2==0)
                swap(A[i],A[sIndex++]);
        }
        
        return A;
    }
};