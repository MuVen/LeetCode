/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static inline int MAX(int a, int b){
    return a > b ? a : b;
}
class Solution {
    //unordered_map<TreeNode*, int> map;
public:
    vector<int> robU(TreeNode* root){
        vector<int> vec(2,0);
        if(root == nullptr)
            return vec;
        
        vector<int> left = robU(root->left);
        vector<int> right = robU(root->right);
        
        vec[0] = root->val + left[1] + right[1];
        vec[1] = MAX(left[0], left[1]) + MAX(right[0], right[1]);
        return vec;
    }
    
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;

        vector<int> res = robU(root);
        return MAX(res[0], res[1]);
    }
};