#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> t(n);
        vector<vector<int>> k(n, t);
        queens(k, 0);
        return change(res);
    }

    void queens(vector<vector<int>> k, int row) {
        for (int i = 0; i < (int)k.size(); i++) {
            if (check(k, i, row)) {
                k[row][i] = 1;
                if (row == (int)(k.size() - 1)) {
                    res.push_back(k);
                    k[row][i] = 0;
                    return;
                }
                queens(k, row+1);
                k[row][i] = 0;

            }
        }
    }

    bool check(vector<vector<int>> map,int col, int row) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < (int)map.size(); j++) {
                if (map[i][j]) {
                    if (abs(i - row) == abs(j - col)) {
                        return false;
                    }
                    if (j == col)
                        return false;
                }
            }
        }
        return true;
    }

    vector<vector<string>> change(vector<vector<vector<int>>> res) {
        std::vector<string> v;
        vector<vector<string>> k;
        //vector<vector<int>> t;
        string tmp = "";
        for (auto i:res) {
            for (auto j : i) {
                for (auto k : j) {
                    if (k == 0) {
                        tmp.push_back('.');
                    } else {
                        tmp.push_back('Q');
                    }
                }
                v.push_back(tmp);
                tmp = "";
            }
            k.push_back(v);
            v.clear();
        }
        return k;
    }
};


int main() {
    Solution t;
    t.solveNQueens(4);
}
