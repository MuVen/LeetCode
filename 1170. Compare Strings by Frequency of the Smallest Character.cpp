class Solution {
public:
    static inline int frequency(string word){
        int freq[26] = {0};
        for(auto ch : word){
            int index = ch - 'a';
            freq[index]++;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0)
                return freq[i];
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fwords(words.size(), 0);
        vector<int> fqueries(queries.size(), 0);
        vector<int> cache(11, -1);
        
        for(int i = 0; i < words.size(); i++)
            fwords[i] = frequency(words[i]);
        for(int i = 0; i < queries.size(); i++)
            fqueries[i] = frequency(queries[i]);

        vector<int> result(queries.size(),0);
        for(int i = 0; i < queries.size(); i++){
            int qval = fqueries[i];
            if(cache[qval] == -1){
                int count = 0;
                for(int j = 0; j < words.size(); j++){
                    if(fwords[j] > qval)
                        count++;
                }
                result[i] = count;
                cache[qval] = count;
            }else
                result[i] = cache[qval];
        }

        return result;
    }
};