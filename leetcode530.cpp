#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
     int min1 = INT32_MAX - 1;
public:
    int getMinimumDifference(TreeNode* root) {
        getMini(root);
        return min1;
    }

    void getMini(TreeNode* root) {
        if (!root) return;
        int left, right;
        if (root->left) {
            left = max(root->left);
            if (min1 > abs(root->val - left)) min1 = abs(root->val - left);
            getMini(root->left);
        }
        if (root->right) {
             right = min(root->right);
             if (min1 > abs(root->val - right)) min1 = abs(right - root->val);
            getMini(root->right);
         }

    }

    int min(TreeNode* root) {
        if (root == NULL) return -1;
        if (root->left == NULL) return root->val;
        return min(root->left);
    }
    int max(TreeNode* root) {
        if (root == NULL) return -1;
        if (root->right == NULL) return root->val;
        return max(root->right);
    }
};
