/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    Node* next = nullptr;
public:
    void flattenUtil(Node* head){
        if(head == nullptr)
            return;
        
        
        flattenUtil(head->child);
        if(head->child){
            Node* nexttemp = head->next;
        
            head->next = head->child;
            head->child->prev = head;

            head->child = nullptr;

            while(head->next)
                head = head->next;

            head->next = nexttemp;
            nexttemp->prev = head;
        }
        
        flattenUtil(head->next);
    }
    
    Node* flatten(Node* head) {
        if(head == nullptr)
            return nullptr;
        flattenUtil(head);
        return head;
    }
};