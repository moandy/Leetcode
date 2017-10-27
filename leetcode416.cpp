#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool flag = false;
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) return false;
        isok(0, nums, target/2);
        return flag;
    }

    void isok(int i, vector<int>& nums, int target) {
        if (target == 0&&i <= nums.size()) {
            flag = true;
        }
        if (i >= nums.size()) return;
        target -= nums[i];
        isok(i+1, nums,target);
        target += nums[i];
        isok(i+1, nums,target);
    }
};

int main(int argc, char const *argv[]) {
    Solution test;
    std::vector<int> v = {1,5,11,5};
    cout << test.canPartition(v);
    return 0;
}
