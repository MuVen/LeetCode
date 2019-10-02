class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        result.resize(2, 0);
        
        int size = numbers.size();
        int left = 0, right = size-1;
        while(left < right){
            if(numbers[left]+numbers[right] == target){
                result[0] = left+1;
                result[1] = right+1;
                return move(result);
            }else if(numbers[left]+numbers[right] < target){
                left++;
            }else{
                right--;
            }
        }
        
        return move(result);
    }
};