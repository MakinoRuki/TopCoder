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
#define N 40000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
bool pm[N];
int p[N];
class ZeroBoard {
public:
	vector<int> solve(int r, int c, vector<int> dt) {
		vector<int> ans;
		ans.clear();
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (dt[i*c+j] == 0) {
					continue;
				}
				cout<<i<<" "<<j<<endl;
				if (j+1<c) {
					if (dt[i*c+j] <= dt[i*c+j+1]) {
						int det = dt[i*c+j];
						ans.push_back(i);
						ans.push_back(j);
						ans.push_back(1);
						ans.push_back(-det);
						dt[i*c+j] -= det;
						dt[i*c+j+1] -= det;
					} else {
						int det = dt[i*c+j] - dt[i*c+j+1];
						if (j+2 < c) {
							ans.push_back(i);
							ans.push_back(j+1);
							ans.push_back(1);
							ans.push_back(det);
							dt[i*c+j+1] += det;
							dt[i*c+j+2] += det;
						} else if (i+1<r) {
							ans.push_back(i);
							ans.push_back(j+1);
							ans.push_back(0);
							ans.push_back(det);
							dt[i*c+j+1] += det;
							dt[(i+1)*c+j+1] += det;
						} else {
							return {-1};
						}
						ans.push_back(i);
						ans.push_back(j);
						ans.push_back(1);
						ans.push_back(-dt[i*c+j]);
						dt[i*c+j] = 0;
						dt[i*c+j+1] = 0;
					}
				}
				if (i+1<r && dt[i*c+j] != 0) {
					if (dt[i*c+j] <= dt[(i+1)*c+j]) {
						int det = dt[i*c+j];
						ans.push_back(i);
						ans.push_back(j);
						ans.push_back(0);
						ans.push_back(-det);
						dt[i*c+j] -= det;
						dt[(i+1)*c+j] -= det;
					} else {
						int det = dt[i*c+j] - dt[(i+1)*c+j];
						if (i+2 < r) {
							ans.push_back(i+1);
							ans.push_back(j);
							ans.push_back(0);
							ans.push_back(det);
							dt[(i+1)*c+j] += det;
							dt[(i+2)*c+j] += det;
						} else if (j-1>=0) {
							ans.push_back(i+1);
							ans.push_back(j-1);
							ans.push_back(1);
							ans.push_back(det);
							dt[(i+1)*c+j-1] += det;
							dt[(i+1)*c+j] += det;
						} else {
							return {-1};
						}
						ans.push_back(i);
						ans.push_back(j);
						ans.push_back(0);
						ans.push_back(-dt[i*c+j]);
						dt[i*c+j] = 0;
						dt[(i+1)*c+j] = 0;
					}
				}
				if (dt[i*c+j] != 0) return {-1};
			}
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (dt[i*c+j] != 0) return {-1};
			}
		}
		return ans;
	}
};
