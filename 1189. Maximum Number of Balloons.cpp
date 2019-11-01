class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int freq[26]={0};
       for(char ch : text){
           int index = ch - 'a';
           freq[index]++;
       }
       
       string name = "balloon";
       int count = 0;
       while(1){
           for(int i = 0; name[i] != '\0'; i++){
                int index = name[i]-'a';
                if(freq[index] == 0)
                    return count;
                freq[index]--;
            }
           count++;
       }
       return count;
    }
};