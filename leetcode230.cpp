#include <iostream>
#include <string>
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
    int kthSmallest(TreeNode* root, int k) {
        int t = find(root->left);
        if (k > t) {
            if (k == t + 1) return root->val;
            else return kthSmallest(root->right, k - t - 1);
        } else {
            return kthSmallest(root->left, k);
        }
    }
    int find(TreeNode* root) {
        if (!root) return 0;
        int left = find(root->left);
        int right = find(root->right);
        return left + right + 1;
    }
};
