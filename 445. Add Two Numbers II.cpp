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
    ListNode* addTwoUtil(ListNode* l1, ListNode* l2, int& carry){
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        ListNode* next = addTwoUtil(l1 ? l1->next: nullptr, l2 ? l2->next : nullptr, carry);
        
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        
        int sum = n1 + n2 + carry;
        if(sum >= 10)
            carry = 1;
        else 
            carry = 0;
        sum = sum % 10;
        
        ListNode* t = new ListNode(sum);
        t->next = next;
        return t;
    }
    
    int len(ListNode* l1){
        int count = 0;
        while(l1){
            count++;
            l1 = l1->next;
        }
        return count;
    }
    
    ListNode* paddZeros(ListNode* list, int diff){
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        diff--;
        
        while(diff--){
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        
        temp->next = list;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ll1 = len(l1);    
        int ll2 = len(l2);
        
        if(ll1 != ll2){
            int diff = ll1 > ll2 ? ll1-ll2 : ll2-ll1;
            if(ll1 > ll2){
                l2 = paddZeros(l2, diff);
            }else if(ll1 < ll2){
                l1 = paddZeros(l1, diff);
            }
        }
        
        int carry = 0;
        auto shead = addTwoUtil(l1,l2, carry);        
        
        if(carry == 1){
            ListNode* ctemp = new ListNode(1);
            ctemp->next = shead;
            return ctemp;
        }
        
        return shead;
    }
};