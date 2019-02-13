#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define N 500005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class SimulateBST {
	public:
		int p;
		int ls[N], rs[N];
		ll ans;
		ll pw[N];
		map<ll, int> ds;
		set<ll> vs;
		int checksum(int n, vector <int> sp, int a, int m) {
			p = sp.size();
			memset(ls, -1, sizeof(ls));
			memset(rs, -1, sizeof(rs));
			ans = 0LL;
			for (int i = 0; i < n; ++i) {
				if (i == 0) pw[i] = 1LL;
				else pw[i] = pw[i - 1] * 100000LL % mod;
			}
			ds.clear();
			vs.clear();
			for (int i = 0; i < n; ++i) {
				ll v = (i < p ? sp[i] : ((ll)a * (ll)sp[i - p] % (ll)m + (ll)ds[sp[i - 1]] + 1LL)) % (ll)m;
			//	cout<<i<<" "<<v<<endl;
				ll res;
				if (vs.find(v) != vs.end()) {
					res = ds[v];
				} else {
					if (vs.empty()) {
						vs.insert(v);
						ds[v] = 0;
						res = 0;
					//	cout<<"x "<<i<<" "<<res<<endl;
					} else {
					//	for (auto itr = vs.begin(); itr != vs.end(); ++itr) {
						//	cout<<"w "<<(*itr)<<endl;
					//	}
						auto ub = vs.lower_bound(v);
					//	cout<<"z "<<(*lb)<<endl;
						if (ub == vs.begin()) {
							res = ds[*vs.begin()] + 1;
							vs.insert(v);
							ds[v] = res;
						} else {
							if (ub == vs.end()) {
								ub--;
								res = ds[*ub] + 1;
								vs.insert(v);
								ds[v] = res;
							} else {
								int l1 = ds[*ub];
								auto lb = ub;
								lb--;
								int l2 = ds[*lb];
								res = max(l1, l2) + 1;
								vs.insert(v);
								ds[v] = res;
							}
						}
						//cout<<"y "<<i<<" "<<*lb<<" "<<res<<endl;
					}
				}
			//	cout<<i<<" "<<res<<endl;
			//	cout<<i<<" "<<res<<endl;
			//	cout<<i<<" "<<res<<endl;
				if (i >= p) sp.push_back(v);
				res = res * pw[i] % mod;
				ans = (ans + res) % mod;
			}
			return ans;
		}
};

/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 500005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class SimulateBST {
	public:
		int p;
		int ls[N], rs[N];
		ll ans;
		ll pw[N];
		int D(int rt, ll v, int d, vector<int>& sp) {
			if (v == sp[rt]) return d;
			if (v < sp[rt]) return D(ls[rt], v, d + 1, sp);
			return D(rs[rt], v, d + 1, sp);
		}
		int I(int rt, int ct, ll v, int d, vector<int>& sp) {
			if (v == sp[rt]) return d;
			if (v < sp[rt]) {
				if (ls[rt] == -1) {
					ls[rt] = ct;
					return d + 1;
				}
				return I(ls[rt], ct, v, d + 1, sp);
			}
			if (rs[rt] == -1) {
				rs[rt] = ct;
				return d + 1;
			}
			return I(rs[rt], ct, v, d + 1, sp);
		}
		int checksum(int n, vector <int> sp, int a, int m) {
			p = sp.size();
			memset(ls, -1, sizeof(ls));
			memset(rs, -1, sizeof(rs));
			ans = 0LL;
			for (int i = 0; i < n; ++i) {
				if (i == 0) pw[i] = 1LL;
				else pw[i] = pw[i - 1] * 100000LL % mod;
			}
			for (int i = 0; i < n; ++i) {
				ll v = (i < p ? sp[i] : ((ll)a * (ll)sp[i - p] % (ll)m + (ll)D(0, sp[i - 1], 0, sp) + 1LL)) % (ll)m;
				ll res = (ll)I(0, i, v, 0, sp);
				cout<<i<<" "<<res<<endl;
			//	cout<<i<<" "<<res<<endl;
				if (i >= p) sp.push_back(v);
				res = res * pw[i] % mod;
				ans = (ans + res) % mod;
			}
			return ans;
		}
};*/
