#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class ValueDivision {
  public:
    int n;
    vector<int> getArray(vector<int> A) {
      n = A.size();
      vector<pair<int, int>> rk;
      rk.clear();
      for (int i = 0; i < n; ++i) {
        rk.push_back(make_pair(A[i], i+1));
      }
      vector<int> ans(n);
      sort(rk.begin(), rk.end());
      set<int> ids;
      ids.clear();
      int cur=rk.back().first;
      int i = n-1;
      while(i>=0) {
        if (rk[i].first == cur) {
          ids.insert(-rk[i].second);
          i--;
        } else {
          int det = min((int)ids.size(), cur - rk[i].first);
          for (int j = 1; j <= det; ++j) {
            auto x = -(*ids.begin());
            ids.erase(ids.begin());
            ans[x-1] = cur-j+1;
          }
          cur = rk[i].first;
        }
      }
      int det = min(cur-1, (int)ids.size());
      for (int i = 1; i <= det; ++i) {
        auto x = -(*ids.begin());
        ids.erase(ids.begin());
        ans[x-1] = cur-i+1;
      }
      while(!ids.empty()) {
        auto x = -(*ids.begin());
        ids.erase(ids.begin());
        ans[x-1] = 1;
      }
      return ans;
    }
};
