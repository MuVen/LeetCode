int days [] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
class Solution {
public:   
    int dayOfYear(string date) {
        int year = 0, month = 0, day = 0;
        for(int i = 0; i < 4; i++){
            year = year*10 + (date[i]-'0');
        }
        for(int i = 5; i < 7; i++){
            month = month*10 + (date[i]-'0');
        }
        for(int i = 8; i < 10; i++){
            day = day*10 + (date[i]-'0');
        }
    
        bool isyleap = (year%4 == 0 && (year%400 == 0 || year%100 != 0));
        int count = 0;
        for(int i = 1; i < month; i++){
            if(i == 2 && isyleap)
                count++;
            count += days[i];
        }
        return count + day;
    }
};