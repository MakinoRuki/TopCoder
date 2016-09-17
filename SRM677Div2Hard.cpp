#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 22
using namespace std;
class PalindromePath {
  public:
    int dp[2][N][N];
    vector<pii> edegs[N];
    int m;
    int shortestLength (int n, vector<int> a, vector<int> b, string c) {
      m = a.size();
      memset(dp, -1, sizeof(dp));
      for (int i = 0; i < m; ++i) {
        edges[a[i]].push_back(mp(b[i], c[i] - 'a'));
        edges[b[i]].push_back(mp(a[i], c[i] - 'a'));
      }
      for (int i = 0; i < n; ++i) {
        dp[0][i][i] = 0;
      }
      for (int i = 0; i < m; ++i) {
        dp[0][a[i]][b[i]] = 1;
        dp[0][b[i]][a[i]] = 1;
      }
      int now = 0;
      int cnt = 0;
      while (true) {
        if (dp[now][0][1] >= 0) return dp[now][0][1];
        if (cnt > n * n) return -1;
        int has = false;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (dp[now][i][j] >= 0) has = true;
          }
        }
        if (!has) return -1;
        cnt++;
        memset(dp[now ^ 1], -1, sizeof(dp[now ^ 1]));
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (dp[now][i][j] >= 0) {
              for (int i2 = 0; i2 < edges[i].size(); ++i2) {
                for (int j2 = 0; j2 < edges[j].size(); ++j2) {
                  if (edges[i][i2].second == edges[j][j2].second) {
                    dp[now ^ 1][edges[i][i2].first][edges[j][j2].first] = dp[now][i][j] + 2;
                  }
                }
              }
            }
          }
        }
        now ^= 1;
      }
      return -1;
    }
};
