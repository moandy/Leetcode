#include <iostream>
#include <vector>
using namespace std;

//wordbreak
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i]=max(j*dp[i-j],max(dp[i],j*(i-j)));
            }
        }
        return dp[n];
    }
};
