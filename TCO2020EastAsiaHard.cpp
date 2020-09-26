#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
class CannonballPyramids {
	public:

		bool dfs(int cur, int cnt, ll sum, ll tar, vector<pair<int,ll>>&cdd, vector<int>& ans) {
			if (cnt>6) return false;
			if (sum==tar) {
				return true;
			}
			for (int i = cur; i < cdd.size(); ++i) {
				if (sum+cdd[i].second<=tar && cnt+1<=6) {
					ans.push_back(cdd[i].first);
					if (dfs(i, cnt+1, sum+cdd[i].second, tar, cdd, ans)) {
						return true;
					}
					ans.pop_back();
				}
			}
			return false;
		}
		vector<int> build(int B) {
			vector<pair<int,ll>> cdd;
			cdd.clear();
			for (int i = 1; i <= 2000; ++i) {
				ll res=(ll)i*(ll)(i+1)*(ll)(2*i+1)/6;
				if (res>B) break;
				cdd.push_back(make_pair(i, res));
			}
			reverse(cdd.begin(), cdd.end());
			vector<int> ans;
			ans.clear();
			dfs(0, 0, 0LL, B, cdd, ans);
			return ans;
		}
};
