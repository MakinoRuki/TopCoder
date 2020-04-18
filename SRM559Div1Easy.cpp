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
class HyperKnight {
public:
	ll countCells(int a, int b, int r, int c, int k) {
		ll ans=0LL;
		if (a > b) swap(a,b);
		vector<ll> rs = {a, b-a, r-2*b, b-a, a};
		vector<ll> cs = {a, b-a, c-2*b, b-a, a};
		vector<vector<int>> cnt = {{2,3,4,3,2},{3,4,6,4,3},{4,6,8,6,4},{3,4,6,4,3},{2,3,4,3,2}};
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (cnt[i][j] == k) {
					ans += rs[i]*cs[j];
				}
			}
		}
		return ans;
	}
};
