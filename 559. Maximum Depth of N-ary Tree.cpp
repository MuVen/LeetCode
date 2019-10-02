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
public:
    void maxDepthUtil(Node* root, int level, int& currlevel){
        if(root == nullptr)
            return;
        
        if(level > currlevel){
            currlevel = level;
        }
        
        for(int i = 0; i < root->children.size(); i++){
            maxDepthUtil(root->children[i], level+1, currlevel);
        }
    }
    
    int maxDepth(Node* root) {
        int currlevel = 0;
        maxDepthUtil(root, 1, currlevel);
        return currlevel;
    }
};