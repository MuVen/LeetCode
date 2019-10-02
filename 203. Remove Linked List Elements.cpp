/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        
        ListNode* thead = head;
        ListNode* prev = nullptr;
        while(head){        
            if(head->val == val){
                if(head == thead && prev == nullptr){
                    thead = head->next;
                    head = head->next;
                    continue;
                }else{
                    prev->next = head->next;
                    head = head->next;
                    continue;
                }
            }
            prev = head;
            head = head->next;
        }
        return thead;
    }
};