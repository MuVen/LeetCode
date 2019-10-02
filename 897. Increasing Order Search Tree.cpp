class Solution {
	TreeNode* nroot = nullptr;
	TreeNode* curr = nullptr;
public:
	void inorder(TreeNode* root){
		if (root == nullptr)
			return;
		inorder(root->left);

		curr->right = root;
		root->left = nullptr;
		curr = curr->right;

		inorder(root->right);
	}

	TreeNode* increasingBST(TreeNode* root) {
		curr = new TreeNode(-1);
		TreeNode* scurr = curr;
		inorder(root);
		return scurr->right;
	}
};