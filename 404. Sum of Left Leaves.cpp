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
    long long int sum;
public:
    void sumOfLeftLeavesUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        if(root->left && root->left->left == nullptr && root->left->right == nullptr){
            sum += root->left->val;
        }
        
        sumOfLeftLeavesUtil(root->left);
        sumOfLeftLeavesUtil(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;

        sum = 0;
        sumOfLeftLeavesUtil(root);
        return sum;
    }
};