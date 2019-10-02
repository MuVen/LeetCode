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
    void distance(TreeNode* root, int x, int d, bool& found, int& fd){
        if(root == nullptr)
            return;
        
        if(root->val == x){
            found = true;
            fd = d;
            return;
        }
        
        if(found)
            return;

        distance(root->left, x, d+1, found, fd);
        distance(root->right, x, d+1, found, fd);
    }

    bool issibiling(TreeNode* root, int x, int y){
        if(root == nullptr)
            return false;
        
        if(root->left && root->right){
            if(root->left->val == x && root->right->val == y)
                return true;
            if(root->left->val == y && root->right->val == x)
                return true;
        }
        
        return issibiling(root->left, x, y) || issibiling(root->right, x, y);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int fd1, fd2;
        bool found = false;
        distance(root, x, 1, found, fd1);
        found = false;
        distance(root, y, 1, found, fd2);
        cout<<fd1<<" "<<fd2<<endl;
        if(fd1 != fd2)
            return false;
        
        bool issiblings = issibiling(root, x, y);
        cout<<"issiblings:"<<issiblings<<endl;
        if(issiblings)
            return false;
        
        return true;
    }
};