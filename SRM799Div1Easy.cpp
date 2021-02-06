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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
class CapriciousSorting {
public:
	int cnt1[50];
	bool cnt2[50];
	void dfs(int bit, vector<int>& num, int l, int r) {
		int id;
		if (bit < 0) return;
		for (id = l; id < r; ++id) {
			if ((num[id]&(1<<bit)) != (num[id+1]&(1<<bit))) {
				break;
			}
		}
		if (id == r) {
			dfs(bit-1, num, l, r);
		} else {
			for (int j = l; j < id; ++j) {
				if ((num[j]&(1<<bit)) != (num[id]&(1<<bit))) {
					cnt2[bit] = true;
					return;
				}
			}
			for (int j = id+2; j <= r; ++j) {
				if ((num[j]&(1<<bit)) != (num[id+1]&(1<<bit))) {
					cnt2[bit]=true;
					return;
				}
			}
			if (num[id]&(1<<bit)) {
				if (cnt1[bit] >= 0 && cnt1[bit] != 1) {
					cnt2[bit]=true;
					return;
				}
				cnt1[bit] = 1;
				dfs(bit-1, num, l, id);
				dfs(bit-1, num, id+1,r);
			} else {
				if (cnt1[bit] >= 0 && cnt1[bit] != 0) {
					cnt2[bit]=true;
					return;
				}
				cnt1[bit] = 0;
				dfs(bit-1, num, l, id);
				dfs(bit-1, num, id+1,r);
			}
		}
	}
	int count(vector<int> num) {
		int n = num.size();
		vector<int> num2;
		for (int i = 0; i < n; ++i) {
			num2.push_back(num[i]);
		}
		sort(num2.begin(), num2.end());
		int i;
		for (i = 1; i < n; ++i) {
			if (num2[i] == num2[i-1]) return 0;
		}
		memset(cnt1, -1, sizeof(cnt1));
		memset(cnt2, false, sizeof(cnt2));
		ll ans = 1LL;
		dfs(29, num, 0, n-1);
		for (int i = 29; i >= 0; --i) {
			if (cnt2[i]) {
				return 0;
			}
			if (cnt1[i] < 0) ans *= 2LL;
		}
		return ans;
	}
};
