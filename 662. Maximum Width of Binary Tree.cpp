#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a,b) ((a)>(b)?((a)-(b)):((b)-(a)))
typedef unsigned long long int ulli;
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> que;
		queue<ulli> qval;
		que.push(root);
		qval.push(0);
		ulli ans = 0;
		while (!que.empty()) {
			int size = que.size();
			ulli minv = UINT64_MAX;
			ulli maxv = 0;
			while (size--) {
				TreeNode* n = que.front(); que.pop();
				ulli index = qval.front(); qval.pop();
				if (n) {
					if (n->left) {
						que.push(n->left);
						qval.push(index * 2 + 1);
					}
					if (n->right) {
						que.push(n->right);
						qval.push(index * 2 + 2);
					}
				}
				minv = min(index, minv);
				maxv = max(index, maxv);
			}
			ans = max(abs(maxv, minv), ans);
		}
		return ans + 1;
	}
};