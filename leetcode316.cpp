// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>

// using namespace std;

// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         sort(s.begin(), s.end());
//         if (s.empty()) return s;
//         for (int i = 1; i < s.size(); i++) {
//         	if (s[i] == s[i-1]) {
//         		s.erase(s.begin() + i);
//         		i--;
//         	}
//         }
//         return s;
//     }
// };

// int main() {
// 	Solution tmp;
// 	string s = "bcabc";
// 	cout << tmp.removeDuplicateLetters(s);
// }