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
class OptimalMemoryGame {
public:
	int findPairs(string s) {
		int n = (int)s.size();
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				cnt[s[i]-'A']++;
			}
		}
		int tot=0;
		int num=0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] == 2) {
				tot++;
			} else if (cnt[i] == 1) {
				num++;
			}
		}
		int det = n - tot * 2 - num;
		if (det <= num) {
			return n/2;
		}
		if (det <= 2) {
			return n/2;
		}
		return tot;
	}
};
