#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[N][N];
class BracketSequenceDiv2 {
  public:
    int n;
    int count (string s) {
      n = s.size();
      memset(dp, 0LL, sizeof(dp));
      dp[0][0] = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          int idx;
          for (idx = i + 1; idx <= n; ++idx) {
            if (s[idx - 1] == '(') break;
          }
          dp[idx][j + 1] = (dp[idx][j + 1] + dp[i][j]) % mod;
          for (idx = i + 1; idx <= n; ++idx) {
            if (s[idx - 1] == ')') break;
          }
          if (j > 0) {
            dp[idx][j - 1] = (dp[idx][j - 1] + dp[i][j]) % mod;
          }
        }
      }
      ll ans = 0LL;
      for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[i][0]) % mod;
      }
      return ans;
    }
};
