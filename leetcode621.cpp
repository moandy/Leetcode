#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int map[26] = {0}, count = 0;
        for (auto i:tasks) {
        	map[i - 'A']++;
        	count = max(count, map[i-'A']);
        }
        int res = (count - 1) * (n + 1);
        for (int i = 0; i < 26; i++) {
        	if (map[i] == count) res++;
        }
        return max((int)tasks.size(), res);
    }
};