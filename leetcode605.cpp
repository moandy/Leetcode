#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        for (size_t i = 1; i < flowerbed.size() - 1; i++) {
          if (flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
            n--;
            i++;
          }
        }
        return n<=0;
    }
};

int main(int argc, char const *argv[]) {
  Solution tmp;
  std::vector<int> v = {1,0,0,0,1,0,0};
  cout << tmp.canPlaceFlowers(v, 2) << endl;
  return 0;
}
