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
#define M 52
#define N 50
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
class TransposeColors {
public:
	int mat[N][N];
	vector<int> move(int n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				mat[i][j] = i+1;
			}
		}
		vector<int> ans;
		ans.clear();
		if (n == 1) return ans;
	//	int tmp = 1;
		mat[0][1] = 0;
		ans.push_back(1);
		while(true) {
		//	bool found=false;
			int c=-1;
			int r = -1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (mat[i][j] == 0) {
						r = i;
						c = j;
						break;
					}
				}
				if (c >= 0) break;
			}
			int c2 = -1;
			for (int j = n-1; j >= 0; --j) {
				if (mat[c][j] == c+1 && j != c) {
					c2 = j;
					break;
				}
			}
			if (c2 < 0) break;
			ans.push_back(c*n+c2);
			mat[r][c] = c+1;
			mat[c][c2] = 0;
		}
		ans.push_back(n*n);
		return ans;
	}
};
