#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        vector<int> l(nums.size()), r(nums.size());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        l[0] = 0, r[0] = sum - nums[0];
        for (int i = 1; i < nums.size(); i++) {
            l[i] = l[i-1] + nums[i-1];
            r[i] = r[i-1] - nums[i];
            if (l[i] == r[i]) return i;
        }
        return -1;
    }
};

int main() {
    Solution t;
    std::vector<int> v = {1,7,3,6,5,6};
    cout << t.pivotIndex(v);
    return 0;
}
