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
    vector<int> num;
    int sum;
public:
    int calcValue(){
        int val = 0;
        int one = 1;
        for(int i = num.size()-1, j = 0; i >= 0; i--, j++){
            val += ((one<<j)*num[i]);
        }
        return val;
    }

    void sumRootToLeafUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        num.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            int val = calcValue();
            //cout<<val<<endl;
            sum += val;
            num.pop_back();
            return;
        }
        
        sumRootToLeafUtil(root->left);
        sumRootToLeafUtil(root->right);
        num.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root == nullptr)
            return 0;

        sum = 0;
        sumRootToLeafUtil(root);
        return sum;
    }
};