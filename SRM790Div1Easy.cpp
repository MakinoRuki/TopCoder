#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 305
using namespace std;
typedef long long ll;
class TheSocialNetwork {
	public:
		const ll mod = 1000000007LL;
		int par[N];
		int find(int u) {
			return u==par[u] ? u : par[u]=find(par[u]);
		}
		ll getpw(ll a, ll b) {
			ll res=1LL;
			while(b) {
				if (b&1) res=res*a%mod;
				a=a*a%mod;
				b/=2;
			}
			return res;
		}
		int minimumCut(int n, int m, vector <int> u, vector <int> v, vector <int> l) {
			ll ans=0LL;
			int tot=n;
			vector<pair<int, pair<int,int>>> rk;
			for (int i = 0; i < m; ++i) {
				rk.push_back(make_pair(l[i], make_pair(u[i], v[i])));
			}
			sort(rk.begin(), rk.end());
			reverse(rk.begin(), rk.end());
			for (int i = 1; i <= n; ++i) {
				par[i] = i;
			}
			for (int i = 0; i < m; ++i) {
				ans = (ans + getpw(2LL, l[i]))%mod;
			}
			for (int i = 0; i < m; ++i) {
				int pu=find(rk[i].second.first);
				int pv=find(rk[i].second.second);
				if (pu != pv) {
					if (tot-1==1) {
						continue;
					}
					tot--;
					par[pu] = pv;
					ans = (ans - getpw(2LL, rk[i].first)+mod)%mod;
				} else {
					ans = (ans - getpw(2LL, rk[i].first)+mod)%mod;
				}
			}
			return ans;
		}
};
