class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int size = machines.size();
        int sum = 0;
        for(auto m : machines)
            sum += m;
        
        if(sum % size != 0)
            return -1;
        
        int avg = sum / size;
        vector<int> leftDresses(size, 0);
        vector<int> rightDresses(size, 0);
        
        for(int i = 1; i < size; i++)
            leftDresses[i] = leftDresses[i-1] + machines[i-1];
        for(int i = size-2; i >= 0; i--)
            rightDresses[i] = rightDresses[i+1] + machines[i+1];
        
        int expLeft = 0, expRight = 0, moves = 0;
        for(int i = 0; i < size; i++){
            expLeft = i * avg;
            expRight = (size-i-1)*avg;
            int left = 0, right = 0;
            if(expLeft > leftDresses[i])
                left = expLeft - leftDresses[i];
            if(expRight > rightDresses[i])
                right = expRight - rightDresses[i];
            moves = max(moves, left + right);
        }
        
        return moves;
    }
};