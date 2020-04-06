#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define N 102
using namespace std;
typedef long long ll;
class RectangleArea {
	public:
		int par[N];
		int find(int x) {
			return x==par[x] ? x : par[x] = find(par[x]);
		}
		int minimumQueries(vector<string> known) {
			int n = known.size();
			int m = known[0].size();
			for (int i = 1; i <= n+m; ++i) {
				par[i] = i;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (known[i][j] == 'Y') {
						int fi = find(i+1);
						int fj = find(n+j+1);
						if (fi != fj) {
							par[fi] = fj;
						}
					}
				}
			}
			int cnt=0;
			for (int i =1; i <= n+m; ++i) {
				par[i] = find(i);
				if (par[i] == i) cnt++;
			}
			return cnt-1;
		}
};
