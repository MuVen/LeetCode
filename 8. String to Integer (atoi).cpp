class Solution {
public:
    int myAtoi(string str) {
        bool isnegative = false;
        long long int num = 0;
        bool isnumbercaptured = false;
        bool isplus = false;
        int maxnum = 214748364;
        int maxdigit = 0;

        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == ' '){
                if(isnegative || isplus || isnumbercaptured)
                   return isnegative ? num*-1 : num;
                continue;
            }
            if(str[i] == '+'){
                if(isplus)
                    return isnegative ? num*-1 : num;
                if(i >= 1 && str[i-1]=='-')
                    return isnegative ? num*-1 : num;
                if(isnumbercaptured)
                    return isnegative ? num*-1 : num;
                isplus = true;
                continue;
            }
            if(str[i] =='-'){
                if(isnegative)
                    return isnegative ? num*-1 : num;
                if(i >= 1 && str[i-1] == '+')
                    return isnegative ? num*-1 : num;
                if(isnumbercaptured)
                    return isnegative ? num*-1 : num;
                isnegative = true;
                continue;
            }
            
            maxdigit = isnegative ? 8 : 7;
            
            if(str[i] >= '0' && str[i] <= '9'){
                if(num > maxnum)
                    return isnegative ? INT_MIN : INT_MAX;
                int cd = (str[i]-'0');
                if(num == maxnum && cd > maxdigit)
                    return isnegative ? INT_MIN : INT_MAX;
                num = num*10 + cd;
                isnumbercaptured = true;
                continue;
            }
            if(!(str[i] >= '0' && str[i] <= '9')){
                break;
            }
        }
        
        if(isnegative)
            num = num * -1;
        
        if(num < INT_MIN)
            num = INT_MIN;
        else if(num > INT_MAX)
            num = INT_MAX;
        
        return num;
    }
};