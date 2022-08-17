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
#define M 200005
#define N 400
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
int id[30][20];
int par[N];
int res[N];
class ItsWhomYouKnow {
public:
	ll simulate(int n, int c, int p, vector<int> cs, vector<int> ps, int sd) {
		set<pair<int,int>> ss;
		ss.clear();
		map<int, int> mp;
		mp.clear();
		map<int, set<pair<int,int>>> qs;
		qs.clear();
		for (int i = 0; i < cs.size(); ++i) {
			if (mp.find(cs[i]) == mp.end()) {
				ss.insert(make_pair(-ps[i], cs[i]));
				mp[cs[i]] = ps[i];
			} else {
				if (ps[i] > mp[cs[i]]) {
					ss.erase(make_pair(-mp[cs[i]], cs[i]]));
					ss.insert(make_pair(-ps[i], cs[i]));
					mp[cs[i]] = ps[i];
				}
			}
		}
		ll ans = 0LL;
		ll st = sd;
		int cur = (int)cs.size();
		for (int i = 0; i < n; ++i) {
			pair<ll,ll> pr1 = getp(st);
			pair<ll,ll> pr2 = getp(st);
			ll c1 = pr1.first;
			ll p1 = pr1.second;
			ll c2 = pr2.first;
			ll p2 = pr2.second;
			qs[c1].insert(make_pair(cur++, p1));
			qs[c2].insert(make_pair(cur++, p2));
			if (ss.empty()) {
				auto s2 = (*qs.begin()).second;
				auto pr = *s2.begin();
				(*qs.begin()).second.erase(pr);
				ans += pr.first * (ll)(i+1);
				st = (st + pr.first) % (1LL<<31);
				int cc = (*qs.begin()).first;
				if (ss.find(make_pair(-mp[cc], cc)) != ss.end()) {
					ss.erase(make_pair(-mp[cc], cc));
				}
				mp[cc] = max(mp[cc], pr.second);
				ss.insert(make_pair(-mp[cc], cc));
				if ((*qs.begin()).second.empty()) {
					qs.erase(*qs.begin());
				}
			} else {
				auto pp = *ss.begin();
				int cc = pp.second;
				auto s2 = qs[cc];
				auto pr = *s2.begin();
				qs[cc].erase(pr);
				ans += pr.first * (ll)(i+1);
				st = (st + pr.first) % (1LL<<31);
				ss.erase(pp);
				mp[cc] = max(mp[cc], pr.second);
				ss.insert(make_pair(-mp[cc], cc));
				if (qs[cc].empty()) {
					qs.erase(cc);
				}
			}
		}
		return ans;
	}
};

int main() {
	
	return 0;
}
