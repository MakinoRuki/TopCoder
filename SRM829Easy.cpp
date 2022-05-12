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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
int dp[200][1300];
class SnookerScoring {
public:
	vector<int> getans(vector<int>& v, int b, int e, int cnt, int sum) {
		vector<int> res = {};
		int y = sum;
		for (int x = cnt; x >= 1; --x) {
			res.push_back(dp[x][y]);
			y -= dp[x][y];
		}
		vector<int> ans;
		ans.clear();
		int j = 0;
		for (int i = b; i <= e; ++i) {
			if (v[i] > 0) {
				ans.push_back(v[i]);
			} else {
				ans.push_back(res[j++]);
			}
		}
		return ans;
	}
	vector<int> scoreN(int n, int r, int c) {
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < 200; ++i) {
			for (int j = 0; j < 1300; ++j) {
				if (dp[i][j] >= 0) {
					for (int k = 2; k <= c+1; ++k) {
						if (i + 1 < 200 && j + k < 1300) {
							dp[i+1][j+k] = k;
						}
					}
				}
			}
		}
		//cout<<"??"<<endl;
		vector<int> v;
		v.clear();
		for (int i = 1; i <= r; ++i) {
			v.push_back(1);
			v.push_back(0);
		}
		for (int i = 2; i <= c+1; ++i) {
			v.push_back(i);
		}
		for (int i = 0; i < v.size(); ++i) {
			for (int j = i; j < v.size(); ++j) {
				int sum = 0;
				int cnt= 0 ;
				for (int k = i; k <= j; ++k) {
					sum += v[k];
					if (v[k] == 0) cnt++;
				}
				if (n >= sum && dp[cnt][n-sum] >= 0) {
					return getans(v, i, j, cnt, n-sum);
				}
			}
		}
		return {};
	}
};
