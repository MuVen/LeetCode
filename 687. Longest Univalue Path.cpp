/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int traversalPath(TreeNode* root, int& maxPath){
        if(root == nullptr)
            return 0;
        
        int left = traversalPath(root->left, maxPath);
        int right = traversalPath(root->right, maxPath);
        
        left = (root->left && (root->left->val == root->val)) ? left + 1 : 0;
        right = (root->right && (root->right->val == root->val)) ? right + 1 : 0;
        maxPath = MAX(maxPath, left+right);
        return MAX(left, right);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int maxPath = INT_MIN;
        traversalPath(root, maxPath);
        return maxPath;
    }
};