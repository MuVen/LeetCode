class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        vector<string> list;
        string temp;
        while(ss >> temp){
            list.push_back(temp);
        }
        
        vector<string> result;
        for(int i = 0; i < list.size()-2; i++){
            if(list[i] == first && list[i+1] == second)
                result.push_back(list[i+2]);
        }
        
        return move(result);
    }
};