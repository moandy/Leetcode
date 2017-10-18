#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            //int n = nums.size();
            vector<int> res;
            map<int, int> tmap;
            set<pair<int, int>> tset;
            for (auto i:nums) tmap[i]++;
            for (auto i:tmap) {
                tset.insert(make_pair(i.second, i.first));
            }
            for (auto iter = tset.rbegin(); iter != tset.rend(); iter++) {
                res.push_back((*iter).second);
                k--;
                if (k == 0) return res;
            }
            return res;
    }
};
