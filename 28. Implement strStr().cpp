class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;

        int i, j;
        for(i = 0; haystack[i] != '\0'; i++){
            for(j = 0; needle[j] !='\0'; j++){
                if(needle[j] != haystack[i+j])
                    break;
            }
            if(needle[j] == '\0')
                return i;
        }
        
        return -1;
    }
};