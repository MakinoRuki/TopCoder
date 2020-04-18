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
class TheDevice {
public:
	int minimumAdditional(vector<string> ps) {
		int n = ps.size();
		int m = ps[0].size();
		int ans=0;
		for (int j = 0; j < m; ++j) {
			int on = 0, zn = 0;
			for (int i = 0; i < n; ++i) {
				if (ps[i][j]=='0') zn++;
				else on++;
			}
			ans = max(ans, max(1-zn,0)+max(2-on,0));
		}
		return ans;
	}
};
