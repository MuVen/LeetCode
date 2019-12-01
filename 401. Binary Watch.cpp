class Solution { 
public:
    inline int setBits(int num){
        int count = 0;
        while(num){
            count++;
            num = num & (num-1);
        }
        return count;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                if(setBits(h) + setBits(m) == num){
                    string temp;
                    temp += to_string(h);
                    temp = m < 10 ? temp +":0"+to_string(m) : temp +":"+to_string(m);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};