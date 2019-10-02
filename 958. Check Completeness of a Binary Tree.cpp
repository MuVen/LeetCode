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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        
        bool didHitNull = false;
        while(!que.empty()){
            int size = que.size();
            bool allNulls = true;
            while(size--){
                auto ms = que.front(); que.pop();               
                if(ms){
                    if(didHitNull == true)
                        return false;
                    allNulls = false;
                    que.push(ms->left);
                    que.push(ms->right);
                }else{
                    didHitNull = true;
                    que.push(nullptr);
                    que.push(nullptr);
                }
            }
            if(allNulls)
                return true;
        }
        return true;
    }
};