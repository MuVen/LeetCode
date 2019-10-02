class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<int> a;
        a.resize(size, 0);
        
        int prod = 1;
        for(int i = 0; i < size; i++){
            a[i] = prod;
            prod *= nums[i];
        }
        
        prod = 1;
        for(int i = size-1; i >= 0; i--){
            a[i] *= prod;
            prod *= nums[i];
        }
        
        return move(a);
    }
};