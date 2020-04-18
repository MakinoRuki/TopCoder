#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define N 52
using namespace std;
typedef long long ll;
class NewArenaPassword {
public:
	int minChange(string op, int k) {
		int n = op.size();
		if (k-1 < n-k) {
			int s=0, t=n-k;
			int res=0;
			for (int i = 0; i < k; ++i) {
				if (op[s+i] != op[t+i]) res++;
			}
			return res;
		} else {
			int s=0, t=n-k;
			int det = t-s;
			//int tot=0;
			int res=0;
			int cnt[26];
			for (int i = 0; i < t; ++i) {
				int tot=0;
				memset(cnt, 0, sizeof(cnt));
				for (int j = i; j < n; j += det) {
					tot++;
					cnt[op[j]-'a']++;
				}
				int maxv = 0;
				for (int j = 0; j < 26; ++j) {
					maxv = max(maxv, cnt[j]);
				}
				//cout<<i<<" "<<tot<<" "<<maxv<<endl;
				res += tot-maxv;
			}
			return res;
		}
		return 0;
	}
};
