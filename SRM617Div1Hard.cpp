// Tag : DP
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class FarStrings {
  public:
  vector<string> ans;
  int n;
  int getdis(const string& s1, const string& s2) {
    int dp[30][30];
    for (int i = 0; i <=n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = 2 * n;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i+1<=n) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
        if (j+1<=n) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
        if (i+1<=n && j+1<=n) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+(s1[i]!=s2[j]));
      }
    }
    return dp[n][n];
  }
  vector<string> find(string t) {
    ans.clear();
    n = t.size();
    for (int i = 0; i < n; ++i) {
      string ss = string(n, '*');
      string ss2 = t;
      for (int j = 0; j < n; ++j) {
        for (int c = 'a'; c <= 'z'; ++c) {
          ss[j] = c;
          int d1 = getdis(ss, t);
          ss2[j] = c;
          int d2 = getdis(ss2, t);
          if (i+1 >= d2 && i+1 <= d1) {
            break;
          }
        }
      }
      ans.push_back(ss);
    }
    return ans;
  }
};
