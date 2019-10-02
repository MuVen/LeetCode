class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		int freqp[26] = { 0 };
		int freqs[26] = { 0 };
		int plen = p.length();
		int slen = s.length();
        if (plen > slen)
			return result;
        
		for (int i = 0; p[i] != '\0'; i++){
			freqp[p[i] - 'a']++;
			freqs[s[i] - 'a']++;
		}

		int fp;
		for (fp= 0; fp < 26; fp++){
			if (freqp[fp] != freqs[fp])
				break;
		}
		if (fp >= 26)result.push_back(0);


		for (int i = 1; i <= slen - plen; i++){
			freqs[s[i - 1] - 'a']--;
			freqs[s[i + plen - 1] - 'a']++;

			int fp;
			for (fp = 0; fp < 26; fp++){
				if (freqp[fp] != freqs[fp])
					break;
			}
			if (fp >= 26)result.push_back(i);
		}

		return move(result);
	}
};