#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
	void breakword(string& s, vector<string>& wordDict, vector<string>& res, string tmp, int id, vector<bool>& dp) {
		for (int len = 1; len + id <= s.size(); len++) {
			if (len + id < s.size()) {
				if (dp[id]&&find(wordDict.begin(), wordDict.end(), s.substr(id, len)) != wordDict.end()) {
					breakword(s,wordDict,res,tmp+s.substr(id,len)+" ", id + len, dp);
				}
			} else {
				res.push_back(tmp + s.substr(id, len));
			}
		}
	}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> dp(s.size()+1,0);
        dp[0]=1;
        //int i,j;
        for (int i = 1; i <= s.size(); i++) {
        	for (int j = i - 1; j>=0; j--) {
        		if (dp[j]&&find(wordDict.begin(), wordDict.end(), s.substr(j, i - j))!=wordDict.end()) {
        			dp[i]=0;
        		}
        	}
        }
        vector<string> res;
        if (dp[s.size()]) {
        	breakword(s, wordDict,res,"",0, dp);
        	return res;
        } else {
        	return res;
        }
    }
};

int main() {
	string s = "catsanddog";
	vector<string> wordDict;
	wordDict = {"cat","cats","and","sand","dog"};
	Solution tmp;
	tmp.wordBreak(s,wordDict);
	return 0;
}