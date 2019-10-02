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
    int moves = 0;
public:
    int distributeCoinsUtil(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = distributeCoinsUtil(root->left);
        int right = distributeCoinsUtil(root->right);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        distributeCoinsUtil(root);
        return moves;
    }
};