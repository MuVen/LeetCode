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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return vector<double>{};
        
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            long long int size = que.size();
            long long int tsize = size;
            long long int sum = 0;
            while(size--){
                TreeNode* n = que.front(); que.pop();
                sum += n->val;
                if(n->left)
                    que.push(n->left);
                if(n->right)
                    que.push(n->right);
            }
            res.push_back((double)sum/tsize);
        }

        return move(res); 
    }
};