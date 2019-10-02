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
    int NOT_MONITORED = 0;
    int HAS_CAMERA = 1;
    int MONITORED_BY_OTHER = 2;
    int count = 0;
public:
    int minCameraCoverUtil(TreeNode* root){
        if(root == nullptr)
            return MONITORED_BY_OTHER;
        
        int left = minCameraCoverUtil(root->left);
        int right = minCameraCoverUtil(root->right);
        
        if(left == NOT_MONITORED || right == NOT_MONITORED){
            count++;
            return HAS_CAMERA;
        }
        
        if(left == HAS_CAMERA || right == HAS_CAMERA){
            return MONITORED_BY_OTHER;
        }
        
        return NOT_MONITORED;
    }
    
    int minCameraCover(TreeNode* root) {
        if(minCameraCoverUtil(root) == NOT_MONITORED)
            count++;
        return count;
    }
};