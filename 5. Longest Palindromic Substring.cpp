class Solution {
public:
    string longestPalindrome(string s) {
		if (s.length() == 0 || s.length() == 1)
			return s;

		int ilen = s.length();
		int low, high;
		int maxLen = 1, start = 0;
		//point expansion based solution
		//expand the pallindrom validation around the variable i
		//there are two cases here, even case, odd case.
		//validate pallidrome at every step.
		for (int i = 1; i < ilen; i++){
			//even case
			low = i - 1; high = i;
			while (low >= 0 && high < ilen && s[low] == s[high]){
				if (high - low + 1 > maxLen){
					maxLen = high - low + 1;
					start = low;
				}
				low--;
				high++;
			}

			//odd case
			low = i - 1; high = i + 1;
			while (low >= 0 && high < ilen && s[low] == s[high]){
				if (high - low + 1 > maxLen){
					maxLen = high - low + 1;
					start = low;
				}
				low--;
				high++;
			}
		}
		return s.substr(start, maxLen);
    }
};