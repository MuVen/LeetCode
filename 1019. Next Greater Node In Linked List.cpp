/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    vector<int> arr;
    vector<int> res;
    stack<int> sta;
public:   
    vector<int> nextLargerNodes(ListNode* head) {
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        res.resize(arr.size(),0);
        for(int i = arr.size()-1; i >= 0; i--){
            while(!sta.empty() && arr[i] >= sta.top())
                sta.pop();
            res[i] = sta.empty() ? 0 : sta.top();
            sta.push(arr[i]);
        }
        return res;
    }
};