class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() <= 1)
            return true;
        bool all_lower = true, all_upper = true;
        for(int i = 1; word[i] != '\0'; i++){
            if(islower(word[i]))
                all_upper = false;
            else
                all_lower = false;
        }
        bool ans = all_lower && isupper(word[0]);
        ans |= all_lower && islower(word[0]);
        ans |= all_upper && isupper(word[0]);
        return ans;
    }
};