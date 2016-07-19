#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CliqueParty {
  public:
    int n;
    int maxsize(vector<int> a, int k) {
      n = a.size();
      sort(a.begin(), a.end());
      int ans = 2;
      for (int b = 0; b < n; ++b) {
        for (int e = b + 1; e < n; ++e) {
          int pre = b;
          int tot = 2;
          int delta = a[e] - a[b];
          for (int i = b + 1; i < e; ++i) {
            if ((a[i] - a[pre]) >= k * delta) {
              pre = i;
              tot++;
            }
          }
          ans = max(ans, tot);
        }
      }
      return ans;
    }
};
