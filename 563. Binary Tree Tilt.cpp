/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int abs(int a, int b){
    return a > b ? a - b : b - a;
}
class Solution {
    int tilt = 0;
public:
    int findTiltUtil(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        int ltilt = findTiltUtil(root->left);
        int rtilt = findTiltUtil(root->right);
        tilt += abs(ltilt, rtilt);
        cout<<ltilt<<" "<<rtilt<<" "<<root->val<<" "<<ltilt + rtilt + root->val<<endl;
        return ltilt + rtilt + root->val;
    }
    
    int findTilt(TreeNode* root) {
        if(root == nullptr)
            return 0;
        findTiltUtil(root);
        return tilt;
    }
};