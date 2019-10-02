#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;
        while(i < m && j < n){
            int min = MIN(nums1[i], nums2[j]);
            ans.push_back(min);
            if(min == nums1[i])
                i++;
            else
                j++;
        }
        
        while(i < m){
            ans.push_back(nums1[i]);
            i++;
        }
        
        while(j < n){
            ans.push_back(nums2[j]);
            j++;
        }
        
        nums1 = move(ans);
    }
};