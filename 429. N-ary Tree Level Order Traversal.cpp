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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return vector<vector<int>>{};
        
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            vector<int> tres;
            while(size--){
                Node* n = que.front(); que.pop();
                tres.push_back(n->val);
                vector<Node*> child = n->children;
                for(int i = 0; i < child.size(); i++){
                    que.push(child[i]);
                }
            }
            res.push_back(tres);
        }
        
        return move(res);
    }
};