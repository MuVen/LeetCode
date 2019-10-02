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
    int tsum;
    int fcount;
public:
    
    void pathSumUtil(TreeNode* root, int mysum){
        if(root == nullptr)        
            return;
        
        mysum = mysum + root->val;
        if(tsum == mysum){
            fcount++;
        }
        
        pathSumUtil(root->left, mysum);
        pathSumUtil(root->right, mysum);
    }
    
    void pathSumT(TreeNode* root){
        if(root == nullptr)
            return;

        pathSumUtil(root, 0);
        pathSumT(root->left);
        pathSumT(root->right);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;

        tsum = sum;
        pathSumT(root);
        return fcount;
    }
};