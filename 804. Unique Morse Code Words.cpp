class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() == 0)
            return 0;

        string str[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> sset;
        for(int i = 0; i < words.size(); i++){
            string s;
            for(int j = 0; words[i][j] != '\0'; j++){
                s += str[words[i][j]-'a'];
            }
            sset.insert(s);
        }
        return sset.size();
    }
};