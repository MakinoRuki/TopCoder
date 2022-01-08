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
#define N 52
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
class OneBattleship {
public:
	vector<string> hit(vector<string> gd) {
		int cnt[3];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < gd.size(); ++i) {
			for (int j = 0; j < gd[i].size(); ++j) {
				if (gd[i][j] == '.') {
					cnt[(i+j)%3]++;
				}
			}
		}
		int id = 0;
		for (int i = 1; i < 3; ++i) {
			if (cnt[i] < cnt[id]) {
				id = i;
			}
		}
		for (int i = 0; i < gd.size(); ++i) {
			for (int j = 0; j < gd[i].size(); ++j) {
				if (gd[i][j] == '.' && ((i+j)%3)==id) {
					gd[i][j] = '*';
				}
			}
		}
		return gd;
	}
};
