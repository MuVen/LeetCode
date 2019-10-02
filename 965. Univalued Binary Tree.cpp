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
    bool isUniValid(TreeNode* root, int& val){
        if(root == nullptr)
            return true;
        
        if(root->val != val)
            return false;
        
        return isUniValid(root->left, val) && isUniValid(root->right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int val = root->val;
        return isUniValid(root, val);
    }
};