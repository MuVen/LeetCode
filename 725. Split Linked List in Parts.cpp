class Solution {
	ListNode* chead = nullptr;
public:

	int getSize(){
		ListNode* thead = chead;
		int count = 0;
		while (thead){
			thead = thead->next;
			count++;
		}
		return count;
	}

	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		chead = root;
		int size = getSize();
		if (size == 0)
			return vector<ListNode*>(k, nullptr);
		vector<int> rsize;
		int esize = size / k;
		rsize.resize(k, esize);
		int resize = size%k;
		for (int i = 0; i < resize; i++)
			rsize[i]++;

		vector<ListNode*> result;
		result.resize(k, nullptr);
		ListNode* prev = nullptr;
		for (int i = 0; i < k; i++){
			ListNode* head = result[i];
			for (int j = 0; j < rsize[i]; j++){
				if (head == nullptr){
					head = chead;
					prev = head;
					chead = chead->next;
					continue;
				}

				prev->next = chead;
				prev = chead;
				chead = chead->next;
			}
			prev->next = nullptr;
			result[i] = head;
		}
		return result;
	}
};