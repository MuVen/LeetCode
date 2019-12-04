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
    ListNode* reverse(ListNode* head, ListNode* node){
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while(head != node){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    /*
		this program is same as reverse node in k pairs. instead of k here we pass 2.
		if node reaches end before the k nodes we return head.
		now we reverse head till node.
		head->next = now call swappairs for node.
		return reversedlist;
	*/
    ListNode* swapPairs(ListNode* head) {
        ListNode* node = head;
        for(int i = 1; i <= 2; i++){
            if(node == nullptr)
                return head;
            node = node->next;
        }
        
        auto node_head = reverse(head, node);
        head->next = swapPairs(node);
        return node_head;
    }
};