#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class ANewHope {
	public:
		int n;
		int count(vector<int> fw, vector<int> lw, int D) {
			n = fw.size();
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				int j;
				for (j = 0; j < n; ++j) {
					if (lw[j] == fw[i]) break;
				}
				if (i < j) ans = max(ans, 1);
				else if (i > j) {
					int del = (n - D);
					ans = max(ans, (i - j + del - 1) / del);
				}
			}
			return ans + 1;
		}
};
