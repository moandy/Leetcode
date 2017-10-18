#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int>&a, pair<string, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>  res;
        map<string, int> tmap;
        for (size_t i = 0; i < words.size(); i++) {
             tmap[words[i]]++;
        }
        vector<pair<string, int>> tmp;
        for (auto i:tmap) tmp.push_back(i);
        sort(tmp.begin(), tmp.end(),compare);
        for (auto i : tmp) {
            res.push_back(i.first);
            k--;
            if (k == 0) return res;
        }
        return res;
    }
};

int main() {
    Solution t;
    vector<string> t1 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    t.topKFrequent(t1, 4);
    return 0;
}
