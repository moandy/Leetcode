#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> k(n);
        vector<vector<int>> dp(m, k);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0&&j==0) dp[0][0] = grid[0][0];
                else if (i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];
                else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0&&j==0) dp[0][0] = grid[0][0];
                else if (i == 0) dp[j][i] = min(dp[j-1][i] + grid[j][i],dp[j][i]);
                else if (j == 0) dp[j][i] = min(dp[j][i-1] + grid[j][i],dp[j][i]);
                else dp[j][i] = min(min(dp[j][i-1], dp[j-1][i]) + grid[j][i], dp[j][i]);
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution t;
    std::vector<std::vector<int>> v = {
        {1,2,3},{4,5,6}
    };
    cout << t.minPathSum(v);
    return 0;
}
