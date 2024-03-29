class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
		if(len == 0)
			return 0;
		//skip trailing space.
        int i = 0;
		while(str[i] == ' '){
			i++;
		}
		
		//findout the sign.
		long int num = 0;
		int sign = 1;
		if(str[i] == '-'){
			sign = sign * -1;
			i++;
		}else if(str[i] == '+'){
			i++;
		}
		
		//declare the num as long, so whenever num >= INT_MAX return INT_MAX.
		//if num <= INT_MIN then return INT_MIN.
		//if other than number you encounter return the result.
		//return number x sign.
		for(; str[i] != '\0'; i++){
            if(str[i] < '0' || str[i] > '9')
                return num * sign;
			num = num * 10 + (str[i]-'0');
            cout<<num<<endl;
			if(sign == 1 && num >= INT_MAX)
				return INT_MAX;
			else if(sign == -1 && -num <= INT_MIN)
				return INT_MIN;
		}
        return num * sign;
    }
};