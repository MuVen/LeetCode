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
public:
    void converBSTUtil(TreeNode* root, int& sum){
        if(root == nullptr)
            return;
        
        converBSTUtil(root->right, sum);   
        sum += root->val;
        root->val = sum;
        converBSTUtil(root->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        converBSTUtil(root, sum);
        return root; 
    }
};