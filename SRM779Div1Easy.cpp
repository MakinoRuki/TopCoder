#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
class ArraySorting {
  public:
    int dp[N][N];
    bool vis[N];
    vector<int> arraySort(vector<int> a) {
      int n = a.size();
      int len = 1;
      memset(dp, -1, sizeof(dp));
      dp[0][len] = 0;
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= len; ++j) {
          dp[i][j] = dp[i-1][j];
        }
      //  if (i == 1) cout<<"*"<<dp[i][1]<<endl;
        int l  = 1;
        int r = len;
        while(l < r) {
          int mid = (l+r)/2;
          if (a[dp[i][mid]] <= a[i]) {
            l = mid+1;
          } else {
            r = mid;
          }
        }
        if (a[dp[i][r]] > a[i]) {
          dp[i][r] = i;
        } else {
          if (r == len && a[dp[i][r]] <= a[i]) {
            len++;
            dp[i][len] = i;
          }
        }
      //  if (i == 1) cout<<"**"<<dp[i][1]<<endl;
      }
    //  for (int i = 1; i <= len; ++i) {
      //  cout<<i<<" "<<dp[2][i]<<endl;
    //  }
      memset(vis, false, sizeof(vis));
      int cur = len;
      int i = n-1;
      while(cur) {
        int id = dp[i][cur];
        vis[id] = true;
        i = id-1;
        cur--;
      }
      int lb = 1;
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
          a[i] = lb;
        } else {
          lb = max(lb, a[i]);
        }
      }
      return a;
    }
};
