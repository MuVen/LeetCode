/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)    
            return " # ";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
    }

    TreeNode* deserializeUtil(istringstream& ss){
        string value;
        ss>>value;
        if(value == "#")
            return nullptr;
        int val = stoi(value);
        TreeNode* root = new TreeNode(val);
        root->left = deserializeUtil(ss);
        root->right = deserializeUtil(ss);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeUtil(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));