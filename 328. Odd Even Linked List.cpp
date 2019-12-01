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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode* odd = head, *even = head->next;
        ListNode* oddh = head, *evenh = head->next;
       
        while(even && even->next){
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenh;
        return oddh;
    }
};
