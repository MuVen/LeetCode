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
    void isubtreeutil(TreeNode* root, string& s, bool left){
        if(root == nullptr){
            if(left)
                s+="lnull";
            else
                s+="rnull";
            return;
        }
        s += "#" + to_string(root->val);
        isubtreeutil(root->left, s, true);
        isubtreeutil(root->right, s, false);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string s1, s2;
        isubtreeutil(s, s1, true);
        isubtreeutil(t, s2, true);
        return s1.find(s2) != string::npos;
    }
};