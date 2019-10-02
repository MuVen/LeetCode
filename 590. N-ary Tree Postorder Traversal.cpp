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
    void postorderUtil(Node* root){
        if(root == nullptr)
            return;

        for(int i = 0; i < root->children.size(); i++){
            postorderUtil(root->children[i]);
        }
        res.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        postorderUtil(root);
        return move(res);
    }
};