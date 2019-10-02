struct node{
    int val;
    node* next;
    node(int tval){
        val = tval;
        next = nullptr;
    }
};

class MyLinkedList {
    node* root;
    node* tail;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = nullptr;
        tail = nullptr;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(root == nullptr)
            return -1;
        
        node* rootc = root;
        int tindex = 0;
        while(rootc){
            rootc = rootc->next;
            tindex++;
            if(tindex == index)
                break;
        }
        
        return rootc && rootc->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* temp = new node(val);
        len++;
        if(root == nullptr && tail == nullptr){
            temp->next = root;
            root = temp;
            tail = temp;
            return;
        }
        
        temp->next = root;
        root = temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* temp = new node(val);
        len++;
        if(root == nullptr && tail == nullptr){
            temp->next = root;
            root = temp;
            tail = temp;
            return;
        }
        
        tail->next = temp;
        tail = temp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(root == nullptr)
            return;
        
        if(index > len)
            return;

        node* rootc = root;
        node* prev = nullptr;
        
        int cindex = 0;
        while(rootc){
            cindex++;
            prev = rootc;
            rootc = rootc->next;
            if(index == cindex)
                break;
        }

        node* temp = new node(val);
        if(tail == temp){
            tail->next = temp;
            tail = temp;
            len++;
            return;
        }
        
        temp->next = prev->next;
        prev->next = temp;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(root == nullptr)
            return;
        
        if(index > len)
            return;

        node* rootc = root;
        node* prev = nullptr;
        
        int cindex = 0;
        while(rootc){
            cindex++;
            prev = rootc;
            rootc = rootc->next;
            if(index == cindex)
                break;
        }

        if(rootc == tail){
           tail = prev;
           tail->next = nullptr;
           len--;
            return;
        }
        
        prev->next = rootc->next;
        delete rootc;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */