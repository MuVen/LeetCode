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
    bool found = false;
    int ans;
public:
    void inorder(TreeNode* root, int& k, int& K){
        if(root == nullptr)
            return;
        
        if(found == true)
            return;
        
        inorder(root->left, k, K);
        k++;
        if(k == K){
            found = true;
            ans = root->val;
            return;
        }
        inorder(root->right, k, K);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        inorder(root, c, k);
        return ans;
    }
};