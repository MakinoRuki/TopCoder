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
class SlowestNim {
public:
	vector <int> move(vector <int> piles) {
		int n = (int)piles.size();
		int tot = 0;
		int id = -1;
		for (int i = 0; i < n; ++i) {
			tot += piles[i];
			if (piles[i] % 2) {
				id = i;
			}
		}
		if (id >= 0) {
			return {tot, id, 1};
		} else {
			int mx = 30;
			for (int i = 0; i < n; ++i) {
				int pw = 0;
				int x = piles[i];
				while(x % 2 == 0) {
					x/=2;
					pw++;
				}
				if (pw < mx) {
					mx = pw;
					id = i;
				}
			}
			return {tot, id, 1};
		}
	}
};
