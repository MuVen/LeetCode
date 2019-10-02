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
    int dleftvalue;
public:
    void findBottomLeftValueUtil(TreeNode* root, int& currlevel, int level){
        if(root == nullptr)
            return;
        
        if(level > currlevel){
            currlevel = level;
            dleftvalue = root->val;
        }
        
        findBottomLeftValueUtil(root->left, currlevel, level+1);
        findBottomLeftValueUtil(root->right, currlevel, level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int currlevel = 0;
        findBottomLeftValueUtil(root, currlevel, 1);
        return dleftvalue;
    }
};