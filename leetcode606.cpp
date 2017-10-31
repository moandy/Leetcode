#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        string s = to_string(t->val);
        if (t->left) s += '(' + tree2str(t->left) + ')';
        else if (t->right) s += "()";
        if (t->right) s += '(' + tree2str(t->right) + ')';
        return s;
    }
};

int main() {
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->left->left = new TreeNode(4);
    t->right = new TreeNode(3);
    Solution tmp;
    cout << tmp.tree2str(t);  /// 1(2(4))(3)
    return 0;
}
