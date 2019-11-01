class Solution {
    unordered_map<long, int> map;
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        string ans;
        if(numerator < 0 ^ denominator < 0){
            ans += "-";
        }
        
        long int num = labs(numerator);
        long int den = labs(denominator);

        long int r = num % den;
        ans += to_string(num / den);
        if(r == 0)
            return ans;

        ans += ".";
        while(r){
            if(map.find(r) != map.end()){
                ans = ans.insert(map[r], "(");
                ans += ")";
                break;
            }
            
            map[r] = ans.size();
            r *= 10;
            ans += to_string(r/den);
            r %= den;
        }

        return ans;
    }
};