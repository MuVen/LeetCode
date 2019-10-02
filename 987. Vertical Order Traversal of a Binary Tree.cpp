#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef pair<int, int> mypair;

class Solution {
	unordered_map<int, vector<mypair>> map;
	int minhd = INT_MAX;
	int maxhd = INT_MIN;
public:
	void vertical(TreeNode* root, int vd, int hd){
		if (root == nullptr)
			return;

		minhd = MIN(minhd, hd);
		maxhd = MAX(maxhd, hd);

		auto& second = map[hd];
		second.push_back({ vd, root->val });

		vertical(root->left, vd + 1, hd - 1);
		vertical(root->right, vd + 1, hd + 1);
	}

	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;

		vertical(root, 0, 0);
		for (int i = minhd; i <= maxhd; i++){
			vector<int> tres;
			auto& second = map[i];
			sort(second.begin(), second.end(), [](const mypair& a, const mypair& b){ 
				if (a.first != b.first)
					return a.first < b.first;
				return a.second < b.second;
			});
			for (int i = 0; i < second.size(); i++){
				tres.push_back(second[i].second);
			}
			res.push_back(tres);
		}

		return res;
	}
};