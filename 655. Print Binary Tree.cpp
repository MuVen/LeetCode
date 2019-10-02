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
    vector<vector<string>> ans;
public:
    int getHeight(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left, right)+1;
    }
    int getWidth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getWidth(root->left);
        int right = getWidth(root->right);
        return max(left,right)*2+1;
    }
    void helper(TreeNode* root, int left, int right, int level){
        if(root == nullptr)
            return;
        
        int mid = left + (right - left)/2;
        ans[level][mid] = to_string(root->val);
        helper(root->left, left, mid-1, level+1);
        helper(root->right, mid+1, right, level+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == nullptr)
            return ans;
        
        int height = getHeight(root);
        int width = getWidth(root);   
        ans.resize(height, vector<string>(width,""));
        helper(root, 0, width-1, 0);
        return move(ans);
    }
};