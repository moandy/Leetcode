#include<vector>
#include<iostream>
#include<algorithm>
#include <set>
#include <utility>
#include <map>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> set;
        map<pair<int, int >,int> pset;
        for (int i = 0; i < nums.size(); i++) {
        	if (set.count(nums[i] - k) != 0) {
        		pset[make_pair(nums[i]-k, nums[i])]++;
        	}
        	set.insert(nums[i]);
        }
        return pset.size();
    }
};

int main() {
	Solution tmp;
	vector<int> nums = {3,1,4,1,5};
	cout << tmp.findPairs(nums,2) << endl;
	return 0;
}