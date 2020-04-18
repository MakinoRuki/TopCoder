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
#define N 52
using namespace std;
typedef long long ll;
class MonstersValley {
public:
	ll dp[N][N*2];
	int minimumPrice(vector<ll> dr, vector <int> pr) {
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		int n = dr.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= 2*i; ++j) {
				if (dp[i][j] >= 0) {
					if (dp[i][j] >= dr[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
					int c= pr[i];
					dp[i+1][j+c] = max(dp[i+1][j+c], dp[i][j]+dr[i]);
				}
			}
		}
		for (int i = 0; i <= 2*n; ++i) {
			if (dp[n][i] >= 0) return i;
		}
		return 2*n+1;
	}
};
