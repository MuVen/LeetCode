/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* thead;
public:
    
    void remove(int n){
        ListNode* temp = thead;
        ListNode* first = thead;
        while(n--){
            temp = temp->next;
        }
        ListNode* prev = nullptr;
        while(temp){
            prev = first;
            first = first->next;
            temp = temp->next;
        }
        if(temp == nullptr && prev == nullptr){
            thead = thead->next;
            return;
        }
        prev->next = first->next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        thead = head;
        remove(n);
        return thead;
    }
};