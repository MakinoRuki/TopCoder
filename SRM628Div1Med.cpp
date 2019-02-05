#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CircuitsConstruction {
public:
	int n;
	int cnt;
	int dfs(string s) {
		cnt++;
		if (s[cnt] == 'X') {
			return 1;
		}
		if (s[cnt] == 'A') {
			int x = dfs(s);
			int y = dfs(s);
			return x + y;
		}
		int x = dfs(s);
		int y = dfs(s);
		return max(x, y);
	}
	int maximizeResistance(string circuit, vector<int> conductors) {
		cnt = -1;
		int res = dfs(circuit);
		sort(conductors.begin(), conductors.end());
		int ans = 0;
		n = conductors.size();
		for (int i = 1; i <= res; ++i) {
			ans += conductors[n - i];
		}
		return ans;
	}
}
