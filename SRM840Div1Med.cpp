#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-10
#define N 7005
#define M 110
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
ll dp[2][N][2];
class AlternatingPermutations {
public:
	int n;
	int count(int n, vector<int> pr) {
		memset(dp, 0LL, sizeof(dp));
		int m = (int)pr.size();
		int flag = 0;
		if (m > 1) {
			if (pr[1] > pr[0]) flag = 1;
			else if (pr[1] == pr[0]) return 0;
			else flag = -1;
		}
		for (int i = 2; i < m; ++i) {
			if (flag > 0) {
				if (pr[i] >= pr[i-1]) return 0;
				flag = -1;
			} else {
				if (pr[i] <= pr[i-1]) return 0;
				flag = 1;
			}
		}
		set<int> ss;
		ss.clear();
		for (int i = 0; i < n; ++i) {
			ss.insert(i);
		}
		for (int i = 0; i < m; ++i) {
			if (ss.find(pr[i]) != ss.end()) {
				ss.erase(pr[i]);
			}
		}
		vector<int> v(ss.begin(), ss.end());
		int sz = (int)v.size();
		if (sz + m != n) {
			return 0;
		}
		if (v.empty()) {
			return 1;
		}
		if (v.size() == 1) {
			if (pr.empty()) return 1;
			if (flag > 0) {
				if (v[0] < pr.back()) return 1;
				return 0;
			} else if (flag < 0) {
				if (v[0] > pr.back()) return 1;
				return 0;
			} else {
				return 1;
			}
		}
		
		dp[0][1][1] = 1;
		dp[0][2][0] = 1;
		for (int i = 2; i < sz; ++i) {
			int now = i&1;
			ll sum[2][N];
			for (int j = 0; j <= sz; ++j) {
				sum[0][j] = (j==0?0LL:(sum[0][j-1]+dp[now][j][0])%mod);
				sum[1][j] = (j==0?0LL:(sum[1][j-1]+dp[now][j][1])%mod);
				for (int k = 0; k < 2; ++k) {
					dp[now^1][j][k] = 0;
				}
			}
			for (int j = 1; j <= i+1; ++j) {
				dp[now^1][j][1] = (dp[now^1][j][1] + (sum[0][sz]-sum[0][j-1]+mod)%mod) % mod;
				dp[now^1][j][0] = (dp[now^1][j][0] + sum[1][j-1]) % mod;
			}
		}
		//cout<<dp[sz&1][2][1]<<" "<<dp[sz&1][1][1]<<endl;
		ll ans = 0LL;
		if (pr.empty()) {
			for (int i = 1; i <= sz; ++i) {
				ans = (ans  + dp[sz&1][i][1]) % mod;
				ans = (ans + dp[sz&1][i][0]) % mod;
			}
			return ans;
		}
		for (int i = 1; i <= sz; ++i) {
			if (v[i-1] > pr.back()) {
				if (flag <= 0) ans = (ans + dp[sz&1][i][0]) % mod;
			} else if (v[i-1] < pr.back()) {
				if (flag >= 0) ans = (ans + dp[sz&1][i][1]) % mod;
			}
		}
		return ans;
	}
};
