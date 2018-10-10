#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class MaxMinTreeGame {
public:
	int n;
	int deg[N];
	int findend(vector<int> edges, vector<int> costs) {
		n = costs.size();
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < edges.size(); ++i) {
			deg[i + 1]++;
			deg[edges[i]]++;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (deg[i] == 1) ans = max(ans, cost[i]);
		}
		return ans;
	}
};
