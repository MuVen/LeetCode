#define MAX(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.length();
		if (size == 0)
			return 0;

		int i = 0, j = 0;
		int ans = 0;
		unordered_map<char, int> mymap;
		for (int i = 0, j = 0; j < size; j++){
			mymap[s[j]]++;
			while (mymap[s[j]] > 1)
				mymap[s[i++]]--;
			ans = MAX(ans, j - i + 1);
		}

		return ans;
	}
};