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
class PastingPaintingDivOne {
public:
	vector<ll> countColors(vector<string> cb, int t) {
		vector<ll> ans(3,0LL);
		int n = cb.size();
		int m = cb[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int d;
				for (d = 0; i+d<n && j+d<m; ++d) {
					if (cb[i+d][j+d]!='.') break;
				}
				if (i+d<n && j+d<m && cb[i+d][j+d] != '.') {
					int id = 0;
					if (cb[i+d][j+d] == 'G') id=1;
					if (cb[i+d][j+d]=='B') id=2;
					if (i==0 || j==0) {
						ans[id] += max(0, t-d);
					} else {
						if (d <= t-1) ans[id]++;
					}
				}
			}
		}
		return ans;
	}
};
