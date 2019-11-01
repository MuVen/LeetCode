class Solution {
public:
	static bool compare(const string& s1, const string& s2) {
		auto p1 = s1.find(" ");
		auto p2 = s2.find(" ");
		string p1c = s1.substr(p1 + 1);
		string p2c = s2.substr(p2 + 1);
		string p1i = s1.substr(0, p1);
		string p2i = s2.substr(0, p2);

		if (p1c > p2c)
			return false;
		else if (p1c < p2c)
			return true;
		return p1i <= p2i;
	}

	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> letters;
		vector<int> digits;

		for (int i = 0; i < logs.size(); ++i) {
			auto index = logs[i].find(" ");
			if (isalpha(logs[i][index + 1]))
				letters.push_back(logs[i]);
			else
				digits.push_back(i);
		}

		sort(letters.begin(), letters.end(), compare);

		for (int i = 0; i < digits.size(); ++i)
			letters.push_back(logs[digits[i]]);

		return letters;
	}
};
