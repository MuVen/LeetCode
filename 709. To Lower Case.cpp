class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; str[i]!='\0';i++){
            if(str[i]>='A'&&str[i]<='Z')
                str[i] = 'a'+(str[i]-'A');
        }
        return str;
    }
};