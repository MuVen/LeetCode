/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> nu;
public:
    int max(int start, int end){
        int maxV = start;
        for(int i = start+1; i < end; i++){
            if(nu[i] > nu[maxV])
                maxV = i;
        }
        return maxV;
    }
    
    TreeNode* construct(int start, int end){
        if(start == end)
            return nullptr;

        int maxI = max(start, end);
        TreeNode* root = new TreeNode(nu[maxI]);
        root->left = construct(start, maxI);
        root->right = construct(maxI+1, end);
        return root;     
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;

        nu = move(nums);
        return construct(0, nu.size());
    }
};