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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
class WordleColors {
public:
	string color(string h, string g) {
		string ans="-----";
		bool mark[5];
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < 5; ++i) {
			if (g[i] == h[i]) {
				ans[i] = 'g';
				mark[i] = true;
			}
		}
		for (int i = 0; i < 5; ++i) {
			if (ans[i] == '-') {
				int j;
				for (j = 0; j < 5; ++j) {
					if (!mark[j] && g[i] == h[j]) {
						ans[i] = 'y';
						mark[j] = true;
						break;
					}
				}
			}
		}
		return ans;
	}
};
