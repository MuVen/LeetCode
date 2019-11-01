class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int person = 0;
        int i = 1;
        while(1){
            if(candies < i){
                result[person % num_people]  += candies;
                break;
            }
            result[person % num_people] += i;
            candies -= i;
            i++;
            person++;
        }
        return result;
    }
};