#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string as = a;
        for (size_t rep = 1; rep <= b.length() / a.length() + 2; rep++, as += a)
            if (as.find(b) != string::npos) return rep;
        return -1;
    }
};

int main() {
  string A = "a";
  string B = "aaa";
  Solution tmp;
  cout << tmp.repeatedStringMatch("abababaaba","aabaaba") << endl;
  return 0;
}
