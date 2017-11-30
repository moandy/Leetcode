#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int max1 = 0;
        vector<int> dp(B.size()+1);
        for (int i = 1; i <= A.size(); i++) {
            for (int j = B.size(); j > 0; j--){
                max1 = max(max1, dp[j] = A[i-1] == B[j-1]?dp[j-1]+1:0);
            }
        }
        return max1;
    }
};

int main(int argc, char const *argv[]) {
    Solution t;
    std::vector<int> v = {0,0,0,0,0,0,0,0,0,0}, v1 = {0,0,0,0,0,0,0,0,0,0};
    cout << t.findLength(v, v1);
    return 0;
}
