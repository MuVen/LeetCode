class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0)
            return false;
        
        int count = 0;
        for(int i = 1; i*i <= num; i++){
            if(num % i == 0){
                count += i;
                if(i*i != num)
                    count += num/i;
            }
        }
        
        return count - num == num;
    }
};