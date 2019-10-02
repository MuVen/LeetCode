/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<int> res;
public:
    void preorderUtil(Node* root){
        if(root == nullptr)
            return;

        res.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++){
            preorderUtil(root->children[i]);
        }
    }

    vector<int> preorder(Node* root) {
        preorderUtil(root);
        return move(res);
    }
};