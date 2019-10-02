struct Trie {
	Trie* childs[26];
	bool isend;
};
Trie nodes[1000000];
int indexT = 0;
Trie* getNode() {
	Trie* temp = &nodes[indexT++];
	temp->isend = false;
	for (int i = 0; i < 26; i++)
		temp->childs[i] = nullptr;
	return temp;
}
Trie* root = nullptr;
void addWord(string& word) {
	Trie* pCrawl = root;
	for (int i = 0; word[i] != '\0'; i++) {
		int index = word[i] - 'a';
		if (pCrawl->childs[index] == nullptr)
			pCrawl->childs[index] = getNode();
		pCrawl = pCrawl->childs[index];
	}
	pCrawl->isend = true;
}

class Solution {
	vector<vector<char>> cboard;
	unordered_set<string> result;
	int row, col;
public:
	void findAll(int x, int y, string res, Trie* root) {
		if (x < 0 || x >= row || y < 0 || y >= col || cboard[x][y] == '\0')
			return;
		
		//cout << res << endl;
		int index = cboard[x][y] - 'a';
		if (root->childs[index]) {
			root = root->childs[index];

			char temp = cboard[x][y];
			cboard[x][y] = '\0';
			res += temp;

			if (root->isend)
				result.insert(res);

			findAll(x - 1, y, res,root);
			findAll(x + 1, y, res, root);
			findAll(x, y + 1, res, root);
			findAll(x, y - 1, res, root);

			cboard[x][y] = temp;
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    cboard = eXZSZ                                  move(board);
		row = cboard.size();
		col = cboard[0].size();
		
		root = getNode();
		for (int i = 0; i < words.size(); i++) {
			addWord(words[i]);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				string temp;
				findAll(i, j, temp, root);
			}
		}

		vector<string> fres;
		for (auto it = result.begin(); it != result.end(); ++it)
			fres.push_back(*it);
		return move(fres);
	}
};