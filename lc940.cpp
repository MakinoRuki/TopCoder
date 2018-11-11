typedef long long ll;
ll mod = 1000000007LL;
class Solution {
public:
    int n;
    ll dp[30];
    int distinctSubseqII(string S) {
        n = S.size();
        ll tot = 1LL;
        memset(dp, 0LL, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            ll tmp = (tot - dp[S[i] - 'a'] + mod) % mod;
            dp[S[i] - 'a'] = tot;
            tot = (tmp + dp[S[i] - 'a']) % mod;
        }
        return tot - 1LL;
    }
};
