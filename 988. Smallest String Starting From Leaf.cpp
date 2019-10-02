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
    string smallestFromLeaf(TreeNode* root, string s = "") {
        if(root == nullptr)
            return "|";
        s = string(1, 'a'+root->val) + s;
        if(root->left == nullptr && root->right == nullptr)
            return s;
        string s1 = smallestFromLeaf(root->left, s); 
        string s2 = smallestFromLeaf(root->right, s); 
        cout<<s1<<" "<<s2<<endl;
        return min(s1,s2);
    }   
};