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
    TreeNode* recoverFromPreorderUtil(string& S, int& index, int level){
        int firstDigitIndex = S.find_first_of("0123456789", index);
        if(firstDigitIndex - index != level)
            return nullptr;
        
        index = S.find("-", firstDigitIndex);
        TreeNode* root = new TreeNode(stoi(S.substr(firstDigitIndex, index)));
        root->left = recoverFromPreorderUtil(S, index, level+1);
        root->right = recoverFromPreorderUtil(S, index, level+1);
        return root;        
    }
    
    TreeNode* recoverFromPreorder(string S) {
        int index = S.find("-");
        TreeNode* root = new TreeNode(stoi(S.substr(0, index)));
        root->left = recoverFromPreorderUtil(S, index, 1);
        root->right = recoverFromPreorderUtil(S, index, 1);
        return root;
    }
};