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
    TreeNode* getMinNode(TreeNode* root){
        if(root == nullptr)
            return nullptr;
        while(root->left){
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if(root->left == nullptr && root->right == nullptr)
                return nullptr;
            else if(root->left == nullptr && root->right != nullptr){
                TreeNode* right = root->right;
                delete root;
                return right;
            }else if(root->left != nullptr && root->right == nullptr){
                TreeNode* left = root->left;
                delete root;
                return left;
            }else {
                TreeNode* min = getMinNode(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }
        return root;
    }
};