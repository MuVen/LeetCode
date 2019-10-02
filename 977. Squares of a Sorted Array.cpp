class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        for(i = 0; i < A.size(); i++){
            if(A[i] > 0)
                break;
        }
        
        int j = i;
        i = i-1;

        vector<int> ans;
        while(i >= 0 && j < A.size()){
            if(A[i]*A[i] < A[j]*A[j]){
                ans.push_back(A[i]*A[i]);
                i--;
            }else{
                ans.push_back(A[j]*A[j]);
                j++;
            }     
        }
        
        while(i >= 0){
            ans.push_back(A[i]*A[i]);
            i--;
        }
        
        while(j < A.size()){
            ans.push_back(A[j]*A[j]);
            j++;
        }
        
        return ans;
    }
};