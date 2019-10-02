/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
    struct DH{
        int height;
        int diameter;
        DH(){
            height = diameter = 0;
        }
    };
public:
    DH getDiameter(TreeNode* root){
        if(root == nullptr)
            return DH();
        
        DH left = getDiameter(root->left);
        DH right = getDiameter(root->right);
        DH middle;
        middle.diameter = MAX(left.height+right.height+1, MAX(left.diameter, right.diameter));
        middle.height = MAX(left.height, right.height) + 1;
        return middle;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return getDiameter(root).diameter-1;
    }
};