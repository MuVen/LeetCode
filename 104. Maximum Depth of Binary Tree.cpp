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
    void maxLevel(TreeNode* root, int& currlevel, int level){
        if(root == nullptr)
            return;
        
        if(level  > currlevel){
            currlevel = level;
        }
        
        maxLevel(root->left, currlevel, level+1);
        maxLevel(root->right, currlevel, level+1);
    }
    
    int maxDepth(TreeNode* root) {
        int cl = 0;
        maxLevel(root, cl, 1);
        return cl;
    }
};