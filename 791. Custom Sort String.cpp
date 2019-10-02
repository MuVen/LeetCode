class Solution {
public:
	string customSortString(string S, string T) {
		if (S == T)
			return S;

		unordered_map<char, int> map;
		for (int i = 0; T[i] != '\0'; i++)
			map[T[i]]++;

		string s;
		for (int i = 0; S[i] != '\0'; i++) {
			int k = map[S[i]];
			while (k--) {
				s.push_back(S[i]);
			}
			map.erase(S[i]);
		}
		for (auto it = map.begin(); it != map.end(); ++it) {
			int k = map[it->first];
			while (k--)
				s.push_back(it->first);
		}

		return s;
	}
};