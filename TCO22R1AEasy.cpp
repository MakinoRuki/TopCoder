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
class SkyscraperReconstruction {
public:
	vector<int> reconstruct(string v) {
		int n = (int)v.size();
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] == 'O') cnt++;
		}
		int x = n - cnt + 1;
		vector<int> ans;
		ans.clear();
		int y = 1;
		for (int i = 0;i < n; ++i) {
			if (v[i] == 'X') {
				ans.push_back(y++);
			} else {
				ans.push_back(x++);
			}
		}
		return ans;
	}
};
