class Solution {
    vector<int> arr;
    int len;
public:
    int candidate(){
        int mindex = 0;
        int count = 1;
        for(int i = 1; i < len; i++){
            arr[i] == arr[mindex] ? count++ : count--;
            if(count == 0)
                mindex = i, count = 1;
        }
        return arr[mindex];
    }
    
    int majorityElement(vector<int>& nums) {
        arr = move(nums);
        len = arr.size();
        if(len == 0)
            return 0;
        int val = candidate();
        int count = 0;
        for(int i = 0; i < len; i++){
            if(arr[i] == val)
                count++;
            if(count > len/2)
                return val;
        }
        return 0;
    }
};