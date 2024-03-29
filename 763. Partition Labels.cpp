typedef pair<int, int> mypair;

class Solution {
	unordered_map<char, mypair> map;
	vector<int> result;
	int slen;
public:
	vector<int> partitionLabels(string s) {
		slen = s.length();
		if (slen == 0)
			return vector<int>{};
		for (int i = 0; s[i] != '\0'; i++){
			if (map.find(s[i]) == map.end()){
				map[s[i]].first = i;
			}
			else
				map[s[i]].second = i;
		}

		int lastpos = -1;
		int maxVal = 0;
		for (int i = 0; i < slen; i++){
			char ch = s[i];
			int findex = map[ch].first;
			int lindex = map[ch].second;

			if (lindex == 0){
				result.push_back(1);
				lastpos = i;
				continue;
			}

			for (int j = i; j < lindex; j++){
				char ch = s[j];
				int sindex = map[ch].second;
				if (sindex > lindex)
					lindex = sindex;
			}

			result.push_back(lindex - lastpos);
			lastpos = lindex;
			i = lastpos;
		}

		return move(result);
	}
};