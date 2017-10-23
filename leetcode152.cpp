#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
{
    int len=nums.size();
    if(len==1)
        return nums[0];

    int maxm=nums[0];
    int minm=nums[0];
    int re=nums[0];
    for(int i=1;i<len;i++)
    {
        int a=max(max(maxm*nums[i],nums[i]),minm*nums[i]);
        int b=min(min(maxm*nums[i],nums[i]),minm*nums[i]);
        if(a>re)
            re=a;
        if(b>re)
            re=b;
        maxm=a;
        minm=b;
    }
    return re;
}
};

int main() {
    vector<int> d = {2,3,-2,4};
    Solution t;
    cout << t.Solution::maxProduct(d);
    return 0;
}
