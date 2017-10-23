#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max = 0;
        unordered_map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        for (auto i : m) {
            if (m.count(i.first+1) != 0) {
                if(i.second + m[i.first + 1] > max) {
                    max = i.second + m[i.first+1];
                }
            }
            // else
            //     if (i.second > max)
            //         max = i.second;
        }
        return max;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << test.findLHS(nums);
    return 0;
}
