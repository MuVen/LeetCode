typedef pair<int, int> mypair;

class Solution {
	unordered_map<int, int> map;
public:
	static bool mysort(const mypair& p1, const mypair& p2) {
		if (p1.second > p2.second)
			return true;
		return false;
	}
	int sumtree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int lsum = sumtree(root->left);
		int rsum = sumtree(root->right);
		int csum = lsum + rsum + root->val;
		map[csum]++;
		return csum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		sumtree(root);
		vector<mypair> vec;
		copy(map.begin(), map.end(), back_inserter(vec));
		sort(vec.begin(), vec.end(), mysort);

		vector<int> result;
		int pfreq = 0;
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			mypair& p = *it;
			if (p.second < pfreq)
				break;
			result.push_back(p.first);
			pfreq = p.second;
		}

		return result;
	}
};
