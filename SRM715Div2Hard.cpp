#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class InPrePost {
	public:
		int n;
		vector<string> ss;
		vector<int> orders;
		bool dfs (vector<int>& pre, vector<int>& in, vector<int>& post) {
			vector<int>v1 = pre;
			vector<int>v2 = in;
			vector<int>v3 = post;
			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());
			sort(v3.begin(), v3.end());
			if (v1 != v2 || v1 != v3) {
				return false;
			}
			if (v1.size() <= 1) return true;
			int root = pre[0];
			int idx = 0;
			for (idx = 0; idx < in.size(); ++idx) {
				if (in[idx] == root) {
					break;
				}
			}
			vector<vector<int> > la (3, vector<int>(idx));
			vector<vector<int> > ra (3, vector<int>(v1.size() - idx));
			la[orders[0]] = vector<int>(pre.begin() + 1, pre.begin() + idx + 1);
			la[orders[2]] = vector<int>(in.begin(), in.begin() + idx);
			la[orders[4]] = vector<int>(post.begin(), post.begin() + idx);
			ra[orders[1]] = vector<int>(pre.begin() + idx + 1, pre.end());
			ra[orders[3]] = vector<int>(in.begin() + idx + 1, in.end());
			ra[orders[5]] = vector<int>(post.begin() + idx, post.end() - 1);
			return dfs(la[0], la[1], la[2]) && dfs(ra[0], ra[1], ra[2]);
		}
		string isPossible(vector<string> s, vector<int> a1, vector<int> a2, vector<int> a3) {
			ss = s;
			orders.clear();
			for (int i = 0; i < 6; ++i) {
				if (s[i] == "pre") orders.push_back(0);
				if (s[i] == "in") orders.push_back(1);
				if (s[i] == "post") orders.push_back(2);
			}
			if (dfs(a1, a2, a3)) {
				return "Possible";
			} else {
				return "Impossible";
			}
		}
};
