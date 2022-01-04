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
#define N 205
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
class MedianSegments {
public:
	ll count(int n, int k, vector<int> pre, int m) {
		int l = (int)pre.size();
		vector<int> a;
		for (int i = 0; i < l; ++i) {
			a.push_back(pre[i]);
		}
		ll st = pre[l-1];
		for (int i = l; i < n; ++i) {
			st = (st * 1103515245LL + 12345) % (1LL<<31);
			a.push_back(st % m);
		}
		map<ll, int> cnt;
		cnt.clear();
		ll sum = 0LL;
		cnt[sum]++;
		for (int i = 0; i < k; ++i) {
			sum += (a[i] > a[k] ? 1 : -1);
			cnt[sum]++;
		}
		ll ans = 0LL;
		for (int i = k; i < n; ++i) {
			if (i > k) {
				sum += (a[i] > a[k] ? 1 : -1);
			}
			ans += cnt[sum];
		}
		return ans;
	}
};
