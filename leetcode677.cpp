#include <iostream>
#include <string>
#include <vector>
#include <set>
#include<map>
using namespace std;


class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        t[key] = val;
    }

    int sum(string prefix) {
        int sum = 0;
        for (auto i:t) {
          if (isprefix(prefix, i.first)) sum+=i.second;
        }
        return sum;
    }
    bool isprefix(string a, string b) {
        if (a.size() > b.size()) return false;
        for (size_t i = 0; i < a.size(); i++) {
          if (a[i] != b[i]) return false;
        }
        return true;
    }
    map<string, int> t;
};
