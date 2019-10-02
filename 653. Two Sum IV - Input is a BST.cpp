/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int abs(int& a, int& b){
    return a > b ? a-b : b-a;
}
class Solution {
    unordered_set<int> set;
public:
         
    bool findTarget(TreeNode* root, int k) { 
        if(root == nullptr)
            return false;
        
        if(set.find(k-root->val) != set.end())
            return true;
        
        set.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};