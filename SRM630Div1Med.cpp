#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class SuffixArrayDiv1 {
	public:
		int n;
		int minimalCharacters(vector <int> SA) {
			n = SA.size();
			vector<int> rks(n + 1, -1);
			for (int i = 0; i < n; ++i) {
				rks[SA[i]] = i;
			}
			int ans = 1;
			for (int i = 0; i < n - 1; ++i) {
				if (rks[SA[i] + 1] > rks[SA[i + 1] + 1]) {
					ans++;
				}
			}
			return ans;
		}
};
