#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 1005
#define pii pair<int, int>
#define mp make_pair
using namespace std;
bool used[N][N];
int deg[N];
class MakingRegularGraph {
	public:
	bool check (vector<int> & x, vector<int> & y, int n) {
		int n0 = 0, n1 = 0;
		for (int i = 0; i < n; ++i) {
			if (deg[i] == 0)n0++;
			if (deg[i] == 1)n1++;
		}
		if (n1 == 0 && n0 >= 1 && n0 <= 2) return false;
		if (n0 == 0 && n1 == 2) {
			for (int i = 0; i < x.size(); ++i) {
				if (deg[x[i]] == 1 && deg[y[i]] == 1) return false;
			}
		}
		return true;
	}
	vector<int> addEdges(int n, vector<int> x, vector<int> y) {
		vector<int> ans;
		ans.clear();
		memset(used, false, sizeof(used));
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < x.size(); ++i) {
			deg[x[i]]++;
			deg[y[i]]++;
			used[x[i]][y[i]] = true;
			used[y[i]][x[i]] = true;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (deg[i] < 2 && deg[j] < 2) {
					if (used[i][j]) continue;
					x.push_back(i);
					y.push_back(j);
					deg[i]++;
					deg[j]++;
					if (check(x, y, n)) {
					//	cout<<i<<" "<<j<<endl;
						ans.push_back(i);
						ans.push_back(j);
						used[i][j] = true;
					} else {
						x.pop_back();
						y.pop_back();
						deg[i]--;
						deg[j]--;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (deg[i] < 2) return {-1};
		}
		return ans;
	}
};
