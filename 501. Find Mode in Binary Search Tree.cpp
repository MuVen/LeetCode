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
    TreeNode* prev = nullptr;
    int maxCount = INT_MIN;
    int count = 0;
    vector<int> ans;
public:
    void inorder(TreeNode* root, bool getList){
        if(root == nullptr)
            return;
        inorder(root->left, getList);
        if(prev && prev->val == root->val)
            count++;
        else
            count = 1;
        if(getList){
            if(count == maxCount)
                ans.push_back(root->val);
        }else{
            maxCount = max(maxCount, count);
        }
        prev = root;
        inorder(root->right, getList);
    }
    void inorderList(TreeNode* root){
        if(root == nullptr)
            return;
        inorderList(root->left);
        if(prev && prev->val == root->val)
            count++;
        else
            count = 1;
        cout<<count<<" ";
        
        prev = root;
        inorderList(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root, false);
        cout<<maxCount<<endl;
        count = 0; prev = nullptr;
        inorder(root, true);
        return ans;
    }
};