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
    int first = INT_MAX;
    int second = INT_MAX;
public:
    int preorder(TreeNode* root){
        if(root == nullptr)
            return INT_MAX;
        
        int leftmin = preorder(root->left);
        int rightmin = preorder(root->right);
        return min(min(leftmin, rightmin), root->val);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr)
            return -1;
        
        first = root->val;
        cout<<first<<endl;
        int lmin = preorder(root->left);   
        cout<<lmin<<endl;
        int rmin = preorder(root->right);
        cout<<rmin<<endl;
        
        if(lmin == INT_MAX && rmin == INT_MAX)
            return -1;
        
        if(first == lmin && first == rmin)
            return -1;
        
        if(first == lmin && first != rmin)
            return rmin;
        
        if(first != lmin && first == rmin)
            return lmin;
        
        return min(lmin, rmin);
    }
};