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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        
        ListNode* thead = head;
        while(head && head->next){
            head = head->next->next;
            thead = thead->next;
        }
        return thead;
    }
};