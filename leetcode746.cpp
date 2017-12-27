#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;
        if (cost.size() == 2) return min(cost[0], cost[1]);
        vector<int> dp(cost.size() + 1, 0);
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        return dp[cost.size()];
    }
};

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution t;
    cout << t.minCostClimbingStairs(cost);
    return 0;
}
