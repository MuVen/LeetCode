/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node{
    TreeNode* node;
    int height;
};

class Solution {
public:
    Node lcaDeepestLeavesUtil(TreeNode* root){
        if(root == nullptr)
            return {nullptr, 0};
        
        Node left = lcaDeepestLeavesUtil(root->left);
        Node right = lcaDeepestLeavesUtil(root->right);
        int height = max(left.height , right.height) + 1;
        if(left.height > right.height)
            return {left.node, height};
        else if(left.height < right.height)
            return {right.node, height};
        return {root, height};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        Node n = lcaDeepestLeavesUtil(root);
        return n.node;
    }
};