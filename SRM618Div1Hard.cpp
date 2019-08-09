// 杂
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class MovingRooksDiv1 {
  public:
  vector<int> ans;
  int n;
  vector<int> move(vector<int> Y1, vector<int> Y2) {
    ans.clear();
    n = Y1.size();
    for (int i = 0; i < n; ++i) {
      if (Y2[i] > Y1[i]) return {-1};
      for (int j = i + 1; j < n; ++j) {
        if (Y1[j] >= Y2[i] && Y1[j] <= Y1[i]) {
          swap(Y1[i], Y1[j]);
          ans.push_back(i);
          ans.push_back(j);
        }
      }
    }
    return ans;
  }
};
