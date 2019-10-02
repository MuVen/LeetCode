#define MIN(a,b) ((a)>(b)?(b):(a))

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        string stra[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        
        int freq[26];
        for(int i = 0; i < 26; i++){
            freq[i] = INT_MAX;
        }
        int afreq[26] = {0};
        int size = A.size()-1;
        
        for(int i = 0; i < A.size(); i++){
            int lfreq[26] = {0};
            string s = A[i];
            for(int j = 0; s[j] != '\0'; j++){
                int index = s[j]-'a';
                afreq[index] = i;
                lfreq[index]++;
            }
            for(int i = 0; i < 26; i++)
                freq[i] = MIN(freq[i], lfreq[i]);
        }
        
        vector<string> res;
        for(int i = 0; i < 26; i++){
            if(afreq[i] == size){
                int val = freq[i];
                while(val--){
                    res.push_back(stra[i]);
                }
            }
        }
        
        return res;
    }
};