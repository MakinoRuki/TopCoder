#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class CheeseRolling {
public:
    vector<int> sta[17];
    vector<int> bits[1<<16];
    int n;
    ll dp[1<<16][17];
    vector<ll> waysToWin (vector<string> wins) {
        n = wins.size();
        for (int i = 0; i < (1<<n); ++i) {
            int cnt = __builtin_popcount(i);
            sta[cnt].push_back(i);
            for (int j = 0; j < n; ++j) {
                if ((1<<j) & i) {
                    bits[i].push_back(j);
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[(1<<i)][i] = 1LL;
        }
        for (int i = 2; i <= n; i *= 2) {
            for (int j = 0; j < sta[i].size(); ++j) {
                int s = sta[i][j];
                for (int p = 0; p < bits[s].size(); ++p) {
                    for (int j2 = 0; j2 < sta[i / 2].size(); ++j2) {
                        int s2 = sta[i / 2][j2];
                        if (!((1<<bits[s][p]) & s2)) continue;
                        int tmp = __builtin_popcount(s2 & s);
                        if (tmp != i / 2) continue;
                        int s3 = s2 ^ s;
                        for (int q = 0; q < bits[s3].size(); ++q) {
                            if (wins[bits[s][p]][bits[s3][q]] == 'Y') {
                                dp[s][bits[s][p]] += dp[s2][bits[s][p]] * dp[s3][bits[s3][q]];
                            }
                        }
                    }
                    dp[s][bits[s][p]] *= 2;
                }
            }
        }
        vector<ll> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(dp[(1<<n) - 1][i]);
        }
        return ans;
    }
};
