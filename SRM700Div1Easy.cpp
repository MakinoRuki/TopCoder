#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class FindingFriend {
	public:
		int n;
		int find (int roomSize, vector<int> leaders, int fp) {
			n = leaders.size();
			for (int i = 0; i < n; ++i) {
				if (leaders[i] == fp) return 1;
			}
			int ans = 0;
			sort(leaders.begin(), leaders.end());
			for (int i = 0; i < n; ++i) {
				if (fp < leaders[i]) break;
				if (i < n - 1) {
					ll num1 = (ll)leaders[i + 1] - 1LL;
					ll num2 = (ll)(i + 1) * (ll)roomSize;
					if (num1 < num2) ans++;
					else {
						if (fp <= num1) ans++;
						else ans = 0;
					}
				} else {
					ans++;
				}
			}
			return ans;
		}
};
