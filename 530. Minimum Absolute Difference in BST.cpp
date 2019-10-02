/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int min(int a, int b){
    return a>b?b:a;
}

int absm(int a, int b){
    return a > b ? a -b : b - a;
}

class Solution {
    int ans = INT_MAX;
    TreeNode* prev = nullptr;
public:
    void getMinimumDifferenceUtil(TreeNode* root) {
        if(root == nullptr)
            return;
        
        getMinimumDifferenceUtil(root->left);
        ans = min(absm(prev ? prev->val : INT_MAX, root ? root->val : INT_MAX), ans);
        prev = root;
        getMinimumDifferenceUtil(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr)
            return INT_MAX;

        getMinimumDifferenceUtil(root);
        return ans;
    }
};