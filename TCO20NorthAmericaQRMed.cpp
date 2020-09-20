#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 102
using namespace std;
typedef long long ll;
class PalindromicSubsequences {
  public:
    ll dp[N][N];
    const ll mod = 10000019LL;
    int count(string s) {
      memset(dp, 0LL, sizeof(dp));
      int n = s.size();
      ll ans=0LL;
      for (int i = n-1; i >= 0; --i) {
        dp[i][i] = 1LL;
        ans = (ans + 1)%mod;
        for (int j = i + 1; j < n; ++j) {
          if (s[i]==s[j]) {
            dp[i][j]=1LL;
            for (int k1=i+1; k1 < j; ++k1) {
              for (int k2=k1; k2 < j; ++k2) {
                if (s[k1]==s[k2]) {
                  dp[i][j]=(dp[i][j]+dp[k1][k2])%mod;
                }
              }
            }
            ans = (ans+dp[i][j])%mod;
          }
          //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
      }
      return ans;
    }
};
