#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define N 200
using namespace std;
class PairedMultiples {
  public:
    int selectedTotal(vector<int> values, int multiple) {
      int n = values.size();
      bool vis[n+2];
      memset(vis, false, sizeof(vis));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i==j) continue;
          if ((values[i]+values[j]) % multiple == 0) {
            vis[i]=true;
            vis[j]=true;
          }
        }
      }
      int sum=0;
      for (int i = 0; i < n; ++i) {
        if (vis[i]) sum += values[i];
      }
      return sum;
    }
};
