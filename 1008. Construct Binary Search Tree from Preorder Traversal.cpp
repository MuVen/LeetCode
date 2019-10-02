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
    vector<int> mpreorder;
    int msize;
public:
    TreeNode* bstFromPreorderUtil(int& index, int min, int max){
        if(index >= msize)
            return nullptr;
        
        TreeNode* root = nullptr;
        if(mpreorder[index] > min && mpreorder[index] < max){
            root = new TreeNode(mpreorder[index++]);
            root->left = bstFromPreorderUtil(index, min, root->val);
            root->right = bstFromPreorderUtil(index, root->val, max);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        mpreorder = move(preorder);
        msize = mpreorder.size();
        int index = 0;
        return bstFromPreorderUtil(index, INT_MIN, INT_MAX);
    }
};