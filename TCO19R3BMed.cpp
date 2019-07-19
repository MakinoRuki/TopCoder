#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 14
using namespace std;
typedef long long ll;
class PrefixComposite {
	public:
		ll dp[N][2];
		vector<int> ba, bb;
		bool iscop(ll x) {
			if (x == 0) return true;
			for (ll i =2; i * i <= x; ++i) {
				if (x % i == 0) return true;
			}
			return false;
		}
		ll dfs1(int cur, int r, ll num) {
			if (dp[cur][r] != -1) return dp[cur][r];
			if (cur == bb.size()) {
				return dp[cur][r] = num;
			}
			if (!r) {
				if (iscop(num*10LL+bb[cur])) {
					ll res =  dfs1(cur+1, r, num*10LL+bb[cur]);
					if (res > -1) return dp[cur][r] = res;
				}
				for (int i = bb[cur]-1; i >= 0; --i) {
					if (iscop(num*10LL+i)) {
						ll res = dfs1(cur+1, !r, num*10LL+i);
						if (res > -1) return dp[cur][r] = res;
					}
				}
			} else {
				for (int i = 9; i >= 0; --i) {
					if (iscop(num*10LL+i)) {
						ll res = dfs1(cur+1, r, num*10LL+i);
						if (res > -1) return dp[cur][r] = res;
					}
				}
			}
			return dp[cur][r] = -2;
		}
		ll dfs2(int cur, int r, ll num) {
			if (dp[cur][r] != -1) return dp[cur][r];
			if (cur == ba.size()) {
				return dp[cur][r] = num;
			}
			if (!r) {
				if (iscop(num*10LL+ba[cur])) {
					ll res = dfs2(cur+1, r, num*10LL+ba[cur]);
					if (res > -1) return dp[cur][r] = res;
				}
				for (int i = ba[cur]+1; i <= 9; ++i) {
					if (iscop(num*10LL+i)) {
						ll res = dfs2(cur+1, !r, num*10LL+i);
						if (res > -1) return dp[cur][r] = res;
					}
				}
			} else {
				for (int i = 0; i <= 9; ++i) {
					if (iscop(num*10LL+i)) {
						ll res = dfs2(cur+1, r, num*10LL+i);
						if (res > -1) return dp[cur][r] = res;
					}
				}
			}
			return dp[cur][r] = -2;
		}
		vector<int> getb(ll x) {
			vector<int> bs;
			bs.clear();
			while(x) {
				bs.push_back(x % 10);
				x /= 10;
			}
			return bs;
		}
		vector<ll> minMax(ll a, ll b) {
			memset(dp, -1, sizeof(dp));
			ba.clear();
			bb.clear();
			ba = getb(a);
			bb = getb(b);
			if (ba.size() < bb.size()) {
				for (int i = ba.size(); i < bb.size(); ++i) {
					ba.push_back(0);
				}
			}
			reverse(ba.begin(), ba.end());
			reverse(bb.begin(), bb.end());
			ll res1 = dfs1(0, 0, 0);
			if (res1 < a) return {};
			memset(dp, -1, sizeof(dp));
			ll res2 = dfs2(0, 0, 0);
			return {res2, res1};
		}
};
