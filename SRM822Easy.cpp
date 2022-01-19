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
bool dp[2][N][M];
class ProbabilisticStreamMinimum {
public:
	double calculate(int n, int k) {
		double ans = 1.0;
		int cnt = 0;
		for (int i = n; i >= 1; --i) {
			if (i <= k) {
				if (cnt == 0) {
					cnt++;
				} else {
					ans *= (1.0 - (double)cnt/(double)(k*k));
					cnt++;
				}
			}
		}
		return ans;
	}
};

