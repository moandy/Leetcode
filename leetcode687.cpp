// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode *left;
//  	TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
 
// class Solution {
// public:
// 	int res = 0;
//     int longestUnivaluePath(TreeNode* root) {
//         if (root == NULL) return 0;
//     }

//     int isok(TreeNode*root, int n) {
//     	if (root == NULL) return 0;
//     	int left = isok(root->left, root-val);
//     	int right = isok(root->right, root->val);
//     	res = max(res, max(left, right));
//     	return res;
//     }
// };