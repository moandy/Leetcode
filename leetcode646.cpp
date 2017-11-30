#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) return true;
    else if (a[0] == b[0]) return a[1] <= b[1];
    else return false;
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), cmp);
        int res = 1, tmp1 = pairs[0][0], tmp2 = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > tmp2) {
                res++;
                tmp2 = pairs[i][1];
            }
            tmp2 = min(pairs[i][1], tmp2);
        }
        return res;
    }
};

int main() {
    Solution t;
    vector<vector<int>> v = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    cout << t.findLongestChain(v);
    return 0;
}
