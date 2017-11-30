#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<int> n(s.size());
        vector<vector<int>> dp(s.size(), n);
        int res = s.size();
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int len = 2; len <= s.size(); len++) {
            for (int i = 0; i + len <= s.size(); i++) {
                if (len == 2) {
                    if (s[i] == s[i + 1]) {
                        dp[i][i+1] = 1;
                        res++;
                    }
                } else {
                    if (s[i] == s[i + len - 1]) {
                        dp[i][i+len-1] = dp[i+1][i+len-2];
                        res = dp[i][i+len-1]?res+1:res;
                    }
                }
            }
        }
        return res;
    }
};

/// if s[i] == s[j], dp[i][j] = dp[i+1][j-1];


int main() {
    Solution t;
    cout << t.countSubstrings("aaa");
    return 0;
}
