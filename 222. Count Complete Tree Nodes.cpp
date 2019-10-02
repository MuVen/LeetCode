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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int lh = 1;
        TreeNode* left = root;
        while(left->left){
            lh++;
            left = left->left;
        }
        
        int rh = 1;
        TreeNode* right = root;
        while(right->right){
            rh++;
            right = right->right;
        }
        
        if(lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};