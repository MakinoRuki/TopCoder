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
#define M 72
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
ll dmg[N];
ll dp[N];
class DevuAndEqualizingLCM {
public:
	int minimumOperationsNeeded(vector<ll> a, vector<ll> b) {
		map<ll, int> cnt;
		cnt.clear();
		map<ll, int> cnt2;
		cnt2.clear();
		for (int i = 0; i < a.size(); ++i) {
			ll x = a[i];
			for (ll j = 2; j * j <= x; ++j) {
				if (x % j == 0) {
					int num=0;
					while(x % j == 0) {
						num++;
						x/=j;
					}
					cnt[j] = max(cnt[j], num);
				}
			}
			if (x > 1) cnt[x] = max(cnt[x], 1);
		}
		int ans=0;
		for (int i = 0; i < b.size(); ++i) {
			ll x = b[i];
			vector<pair<ll,int>> v;
			v.clear();
			for (ll j = 2; j * j <= x; ++j) {
				if (x % j == 0) {
					int num=0;
					while(x % j == 0) {
						num++;
						x/=j;
					}
					v.push_back(make_pair(j, num));
					cnt2[j] = max(cnt2[j], num);
				}
			}
			if (x > 1) {
				v.push_back(make_pair(x, 1));
				cnt2[x] = max(cnt2[x], 1);
			}
			int j;
			for (j = 0; j < v.size(); ++j) {
				if (cnt.find(v[j].first) == cnt.end() || cnt[v[j].first] < v[j].second) {
					break;
				}
			}
			if (j < v.size()) ans++;
		}
		bool found=false;
		for (auto itr : cnt) {
			if (cnt2.find(itr.first) == cnt2.end() || cnt2[itr.first] < itr.second) {
				found=true;
				break;
			}
		}
		if (found) ans = max(ans, 1);
		return ans;
	}
};
