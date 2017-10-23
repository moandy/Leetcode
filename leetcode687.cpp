#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
 	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
     int helper(TreeNode* root, int val)
     {
         if(!root || root->val != val) return 0;
         return 1 + max(helper(root->left,val),helper(root->right,val));
     }
     int longestUnivaluePath(TreeNode* root) {
         if(!root) return 0;
         int sub = max(longestUnivaluePath(root->left),longestUnivaluePath(root->right));
         return max(sub,helper(root->left,root->val) + helper(root->right,root->val));
     }
 };
