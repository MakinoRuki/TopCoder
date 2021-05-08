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
#define eps 1e-7
#define M 52
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
vector<int> mp[N];
ll cnt1[N];
ll cnt2[N];
class ThreeDChessRooks {
public:
	ll count(int c, int r, vector<int> xp, vector<int> yp, vector<int> zp, int seed) {
		vector<int> X(r), Y(r), Z(r);

		int l = xp.size();
		for (int i=0; i<l; ++i) { X[i]=xp[i]; Y[i]=yp[i]; Z[i]=zp[i]; }

		long long state = seed;
		for (int i=l; i<r; ++i) {
		    state = (state * 1103515245 + 12345) % (1LL << 31);
		    X[i] = state % c;
		    state = (state * 1103515245 + 12345) % (1LL << 31);
		    Y[i] = state % c;
		    state = (state * 1103515245 + 12345) % (1LL << 31);
		    Z[i] = state % c;
		}
		 // for (int i = 0; i < r; ++i) {
		 // 	cout<<i<<" "<<X[i]<<" "<<Y[i]<<" "<<Z[i]<<endl;
		 // }
		ll ans = 0LL;
		for (int i = 0; i < c; ++i) {
			mp[i].clear();
		}
		for (int i = 0; i < r; ++i) {
			mp[X[i]].push_back(i);
		}
		for (int i = 0; i < c; ++i) {
			cnt1[i] = 0;
			cnt2[i] = 0;
		}
		for (int i = 0; i < c; ++i) {
			auto v = mp[i];
			if (v.size()<=1) continue;
			map<pair<int,int>,ll> cnt;
			cnt.clear();
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				cnt1[Y[id]]++;
				cnt2[Z[id]]++;
				cnt[make_pair(Y[id], Z[id])]++;
			}
			ll tot = (ll)v.size();
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				ll tmp = tot-1-(cnt1[Y[id]]-1)-(cnt2[Z[id]]-1)+cnt[make_pair(Y[id], Z[id])]-1;
				ans += tmp;
			//	if (id == 0) cout<<Y[id]<<" "<<Z[id]<<" "<<tot<<" "<<cnt1[Y[id]]<<" "<<cnt2[Z[id]]<<" "<<cnt[make_pair(Y[id], Z[id])]<<endl;
				//cout<<id<<" "<<ans<<endl;
			}
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				cnt1[Y[id]]--;
				cnt2[Z[id]]--;
			}
		}
//		cout<<ans<<endl;
		for (int i = 0; i < c; ++i) {
			mp[i].clear();
		}
		for (int i = 0; i < r; ++i) {
			mp[Y[i]].push_back(i);
		}
		for (int i = 0; i < c; ++i) {
			cnt1[i] = 0;
			cnt2[i] = 0;
		}
		for (int i = 0; i < c; ++i) {
			auto v = mp[i];
			if (v.size()<=1) continue;
			map<pair<int,int>,ll> cnt;
			cnt.clear();
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				cnt1[X[id]]++;
				cnt2[Z[id]]++;
				cnt[make_pair(X[id], Z[id])]++;
			}
			ll tot = (ll)v.size();
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				ll tmp = tot-1-(cnt1[X[id]]-1)-(cnt2[Z[id]]-1)+cnt[make_pair(X[id], Z[id])]-1;
				ans += tmp;
			}
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				cnt1[X[id]]--;
				cnt2[Z[id]]--;
			}
		}
//		cout<<ans<<endl;
		for (int i = 0; i < c; ++i) {
			mp[i].clear();
		}
		for (int i = 0; i < r; ++i) {
			mp[Z[i]].push_back(i);
		}
		for (int i = 0; i < c; ++i) {
			cnt1[i] = 0;
			cnt2[i] = 0;
		}
		for (int i = 0; i < c; ++i) {
			auto v = mp[i];
			if (v.size()<=1) continue;
			map<pair<int,int>,ll> cnt;
			cnt.clear();
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				cnt1[X[id]]++;
				cnt2[Y[id]]++;
				cnt[make_pair(X[id], Y[id])]++;
			}
			ll tot = (ll)v.size();
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				ll tmp = tot-1-(cnt1[X[id]]-1)-(cnt2[Y[id]]-1)+cnt[make_pair(X[id], Y[id])]-1;
				ans += tmp;
				//cout<<i<<" "<<"id="<<id<<" "<<ans<<endl;
			}
			for (int j = 0; j < v.size(); ++j) {
				int id = v[j];
				cnt1[X[id]]--;
				cnt2[Y[id]]--;
			}
		}
//		cout<<ans<<endl;
		map<pair<ll,ll>, vector<pair<int,int>>> mp2;
		mp2.clear();
		for (int i = 0; i < r; ++i) {
			mp2[make_pair(X[i], Y[i])].push_back(make_pair(Z[i],i));
		}
		for (auto itr : mp2) {
			auto v = itr.second;
			sort(v.begin(), v.end());
			//ll tot = (ll)v.size();
			vector<pair<int,ll>> ns;
			ns.clear();
			for (int i = 0 ;i < v.size(); ++i) {
				if (ns.empty() || ns.back().first != v[i].first) {
					ns.push_back(make_pair(v[i].first, 1));
				} else {
					ns.back().second++;
				}
			}
			for (int i = 0; i < ns.size(); ++i) {
				ll tmp = (ll)v.size()-ns[i].second;
				if (ns[i].first == 0 && i+1<ns.size() && ns[i+1].first == 1) {
					tmp -= ns[i+1].second;
				} else if (ns[i].first ==c-1 && i-1>=0 && ns[i-1].first==c-2) {
					tmp -= ns[i-1].second;
				}
				ans += (ll)ns[i].second * tmp;
			}
		}
		mp2.clear();
		for (int i = 0; i < r; ++i) {
			mp2[make_pair(Z[i], Y[i])].push_back(make_pair(X[i],i));
		}
		for (auto itr : mp2) {
			auto v = itr.second;
			sort(v.begin(), v.end());
		//	ll tot = (ll)v.size();
			vector<pair<int,ll>> ns;
			ns.clear();
			for (int i = 0 ;i < v.size(); ++i) {
				if (ns.empty() || ns.back().first != v[i].first) {
					ns.push_back(make_pair(v[i].first, 1));
				} else {
					ns.back().second++;
				}
			}
			for (int i = 0; i < ns.size(); ++i) {
				ll tmp = (ll)v.size()-ns[i].second;
				if (ns[i].first == 0 && i+1<ns.size() && ns[i+1].first == 1) {
					tmp -= ns[i+1].second;
				} else if (ns[i].first ==c-1 && i-1>=0 && ns[i-1].first==c-2) {
					tmp -= ns[i-1].second;
				}
				ans += (ll)ns[i].second * tmp;
			}
		}
	//	cout<<ans<<endl;
		mp2.clear();
		for (int i = 0; i < r; ++i) {
			mp2[make_pair(X[i], Z[i])].push_back(make_pair(Y[i],i));
		}
		for (auto itr : mp2) {
			auto v = itr.second;
			//cout<<"x="<<itr.first.first<<" "<<itr.first.second<<" "<<v.size()<<endl;
			sort(v.begin(), v.end());
		//	ll tot = (ll)v.size();
			vector<pair<int,ll>> ns;
			ns.clear();
			for (int i = 0 ;i < v.size(); ++i) {
				if (ns.empty() || ns.back().first != v[i].first) {
					ns.push_back(make_pair(v[i].first, 1));
				} else {
					ns.back().second++;
				}
			}
			for (int i = 0; i < ns.size(); ++i) {
				ll tmp = (ll)v.size()-ns[i].second;
				if (ns[i].first == 0 && i+1<ns.size() && ns[i+1].first == 1) {
					tmp -= ns[i+1].second;
				} else if (ns[i].first ==c-1 && i-1>=0 && ns[i-1].first==c-2) {
					tmp -= ns[i-1].second;
				}
				ans += (ll)ns[i].second * tmp;
			}
		}
		return ans;
	}
};
