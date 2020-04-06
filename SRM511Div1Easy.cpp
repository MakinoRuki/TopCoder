#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#define N 52
using namespace std;
typedef long long ll;
class Zoo {
	public:
		ll theCount(vector<int> ans) {
			map<int, int> cnt;
			int n = ans.size();
			for (int i = 0; i < n; ++i) {
				cnt[ans[i]]++;
			}
			bool mo = false;
			int pre = -1;
			ll tot = 1LL;
			for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
				if (itr == cnt.begin()) {
					if (itr->second > 2) return 0;
					if (itr->first != 0) return 0;
					if (itr->second == 1) mo= true;
					pre = itr->first;
				} else {
					if (itr->first != pre+1) return 0;
					if (mo && itr->second != 1) return 0;
					if (itr->second > 2) return 0;
					if (itr->second == 1) mo = true;
					pre = itr->first;
				}
				if (itr->second == 2) tot *= 2LL;
			}
			if (mo) tot *= 2LL;
			return tot;
		}
};
