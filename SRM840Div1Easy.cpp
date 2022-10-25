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
#define N 500005
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
int par[N];
ll cnt[N];
map<int, int> idx;
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}
ll getpw(ll x, ll y) {
	ll res = 1LL;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
class Postcards {
public:
	int n;
	int count(int n, int y, int sd) {
		idx.clear();
		for (int i = 1; i <= 500000; ++i) {
			par[i] = i;
		}
		ll tot = (ll)n * (ll)(n+1) % mod * (ll)(2*n+1) % mod;
		tot = tot * getpw(6LL, mod-2) % mod;
		ll tot2 = (ll)n * (ll)(n+1) % mod;
		tot2 = tot2 * getpw(2LL, mod-2) % mod;
		tot = (tot - tot2 + mod) % mod;
		ll st = sd;
		ll ans = 0LL;
		int num=0;
		ll cur = tot;
		for (int i = 0; i < y; ++i) {
			st = (st * 1103515245LL + 12345LL) % (1LL<<31);
			int x = st % n;
			st = (st * 1103515245LL + 12345LL) % (1LL<<31);
			int y = st % n;
			if (idx.find(x) == idx.end()) {
				idx[x] = ++num;
				cnt[num] = x+1;
			}
			if (idx.find(y) == idx.end()) {
				idx[y] = ++num;
				cnt[num] = y+1;
			}
			int x1 = idx[x];
			int y1 = idx[y];
			int px = find(x1);
			int py = find(y1);
			if (px != py) {
				ll n1 = cnt[px];
				ll n2 = cnt[py];
				ll d1 = (n1%mod) * (((n1-1)+mod)%mod) % mod;
				ll d2 = (n2%mod) * (((n2-1)+mod)%mod) % mod;
				cur = (cur - d1 + mod) % mod;
				cur = (cur - d2 + mod) % mod;
				cnt[py] += cnt[px];
				par[px] = py;
				ll d3 = (cnt[py]%mod) * (((cnt[py] - 1)+mod)%mod) % mod;
				cur = (cur + d3) % mod;
			}
			ans = (ans + cur) % mod;
		}
		return ans;
	}
};
