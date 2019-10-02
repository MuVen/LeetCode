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
    inline int getLength(ListNode* n){
        if(n == nullptr)
            return 0;
        int count = 0;
        while(n){
            count++;
            n = n->next;
        }
        return count;
    }
    
    inline ListNode* getINode(ListNode* headA, ListNode* headB){
            while(headA && headB){
                if(headA == headB)
                    return headA;
                headA = headA->next;
                headB = headB->next;
            }
            return nullptr;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        
        int diff = l1 > l2 ? l1 - l2 : l2 - l1;
        if(diff == 0)
            return getINode(headA, headB);
        
        if(l1 > l2){
            while(headA && diff != 0){
                headA = headA->next;
                diff--;
            }
            return getINode(headA, headB);
        }
        
        while(headB && diff != 0){
            headB = headB->next;
            diff--;
        }
        return getINode(headA, headB);
    }
};