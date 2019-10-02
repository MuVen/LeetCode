class Solution {
public:
    string defangIPaddr(string address) {
        string defang;
        string number;
        int i = 0;
        while(1){
            for(; address[i] != '\0'; i++){
                if(address[i] == '.')
                    break;
                number.append(1, address[i]);
            }
            if(address[i]=='\0'){
                defang += number;
                break;
            }
            defang += number;
            defang.append(1,'[').append(1,'.').append(1,']');
            number.clear();
            i++;
        }
        return defang;
    }
};