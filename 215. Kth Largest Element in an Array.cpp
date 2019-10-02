class Solution {
    vector<int> heap;
    int hsize;
public:
    void maxHeapify(int index, int size){
        int largest = index;
        int left = 2*largest+1;
        int right = 2*largest+2;
        if(left < size && heap[left] > heap[largest])
            largest = left;
        if(right < size && heap[right] > heap[largest])
            largest = right;
        if(largest != index){
            swap(heap[largest], heap[index]);
            maxHeapify(largest, size);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        hsize = nums.size();       
        if(hsize == 0)
            return 0;

        heap = move(nums);
        for(int i = hsize/2-1; i >= 0; i--)
            maxHeapify(i, hsize);

        int num = 0;
        for(int i = 1; i <= k; i++){
            maxHeapify(0, hsize);
            num = heap[0];
            swap(heap[0], heap[hsize-1]);
            hsize--;
        }
        return num;
    }
};