#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        std::vector<int> v(n, 0);
        vector<vector<int>> map(n, v);
        queen(map, 0);
        return count;
    }

    bool check(vector<vector<int>> map, int col, int row) {
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

    void queen(vector<vector<int>> map, int row) {
        for (size_t i = 0; i < map.size(); i++) {
            if (check(map, i, row)) {
                //count++;
                map[row][i] = 1;
                if (row == (int)(map.size() - 1)) {
                    map[row][i] = 0;
                    count++;
                    return;
                }
                queen(map, row+1);
                map[row][i] = 0;
            }
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution tmp;
    cout << tmp.totalNQueens(4);
    return 0;
}
