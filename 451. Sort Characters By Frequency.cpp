typedef pair<char, int> mypair;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> map;
		for (int i = 0; s[i] != '\0'; i++)
			map[s[i]]++;
		vector<mypair> vec;
		copy(map.begin(), map.end(), back_inserter(vec));
		sort(vec.begin(), vec.end(), [](const mypair& p1, const mypair& p2){
			if (p1.second > p2.second)
				return true;
			return false;
		});
		string ans;
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			mypair mp = *it;
			char ch = mp.first;
 			for (int i = 0; i < mp.second; i++)
				ans += ch;
		}
		return ans;
	}
};