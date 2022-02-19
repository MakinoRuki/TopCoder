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
#define M 200005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
int ss[N], ff[N];
ll h[N];
class ExactRate {
public:
	vector<int> getLongest(int n, int sd, int tr, int s, int f) {
		memset(ss, 0, sizeof(ss));
		memset(ff, 0, sizeof(ff));
		map<int, int> id;
		id.clear();
		h[1] = ((ll)sd * 1103515245LL + 12345) % (1LL<<31);
		for (int i= 2; i <= n; ++i) {
			h[i] = (h[i-1] * 1103515245LL + 12345) % (1LL<<31);
		}
		for (int i = 2; i <= n; ++i) {
			ss[i] = ss[i-1];
			ff[i] = ff[i-1];
			if (h[i] > tr) {
				ss[i]++;
			} else {
				ff[i]++;
			}
		}
	//	cout<<ss[5]<<" "<<ff[5]<<endl;
		id[0] = 0;
		int b = -1, e = -1;
		for (int i = 1; i <= n; ++i) {
			ll det = (ll)f * (ll)ss[i] - (ll)s * (ll)ff[i];
			if (id.find(det) != id.end()) {
				int pre = id[det];
				if (b < 0 || i - pre > e-b+1 || ((i-pre==e-b+1) && pre+1<b)) {
					b = pre+1;
					e = i;
				}
			} else {
				id[det] = i;
			}
		}
		if (b < 0) {
			return {0,0};
		} else {
			return {b-1, e};
		}
	}
};

