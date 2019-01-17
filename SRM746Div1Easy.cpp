#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class ChangeDistances {
	public:
		int n;
		vector<string> ans;
		vector <string> findGraph(vector <string> g) {
			n = g.size();
			ans.clear();
			for (int i = 0; i < n; ++i) {
				string res = g[i];
				for (int j = 0; j < n; ++j) {
					if (j != i) {
						if (g[i][j] == '0') res[j] = '1';
						else res[j] = '0';
					}
				}
				ans.push_back(res);
			}
			return ans;
		}
};
