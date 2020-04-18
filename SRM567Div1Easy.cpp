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
#define N 80000
using namespace std;
typedef long long ll;
class TheSquareRootDilemma {
public:
	ll num[N];
	int countPairs(int n, int m) {
		memset(num, 0, sizeof(num));
		ll ans=0LL;
		for (int i = 1; i <= n; ++i) {
			int x = i;
			int res=1;
			for (int j = 2; j * j <= x; ++j) {
				int cnt=0;
				while(x%j==0) {
					cnt++;
					x/=j;
				}
				if (cnt&1) res*=j;
			}
			if (x>1) res*=x;
			num[res]++;
		}
		for (int i = 1; i <= m; ++i) {
			int x=i;
			int res=1;
			for (int j = 2; j*j <= x; ++j) {
				int cnt=0;
				while(x%j==0) {
					cnt++;
					x/=j;
				}
				if (cnt&1) res*=j;
			}
			if (x>1) res*=x;
			ans += num[res];
		}
		return ans;
	}
};
