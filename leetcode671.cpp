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
    int min1 = INT32_MAX, min2 = INT32_MAX;
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        return min2 == INT32_MAX?-1:min2;
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        if (root->val < min1) {
            min2 = min1;
            min1 = root->val;
        } else if (root->val > min1 && root->val < min2) {
            min2 = root->val;
        }
        inorder(root->left);
        inorder(root->right);
    }
};
