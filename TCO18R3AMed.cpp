#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
typedef long long ll;
class ProductThreshold {
	public:
		ll a[N];
		int cnt[N];
		ll subarrayCount(int n, int limit, vector<int> apre, int spread, int offset) {
			int p = apre.size();
			for (int i = 0; i < p; ++i) {
				a[i] = apre[i];
			}
			ll seed = abs(a[p - 1]);
			for (int i = p; i < n; ++i) {
				seed = (seed * 1103515245LL + 12345LL) % (1LL<<31);
				a[i] = (seed % spread) + offset;
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = n - 1; i >= 0; --i) {
				cnt[i] = cnt[i + 1];
				if (a[i] < 0) cnt[i]++;
			}
			ll mul = 1LL;
			int zero = n;
			ll ans = 0LL;
			int evensum = 0;
			int oddsum = 0;
			int pre = n;
			int j = n - 1;
			for (int i = n - 1; i >= 0; --i) {
				if (a[i] == 0) {
					zero = i;
					ans += n - i;
					mul = 1LL;
					evensum = 0;
					oddsum = 0;
					pre = i;
					j = i - 1;
				} else {
					if (abs(a[i]) > 1) {
						mul *= abs(a[i]);
						while(j >= i) {
							if (mul > limit) {
								mul /= abs(a[j]);
								if (a[j] < 0) {
									evensum += pre - j;
									swap(evensum, oddsum);
									pre = j;
								}
								j--;
							} else {
								break;
							}
						}
					}
					if (j >= i) ans += j - i + 1;
					int num = cnt[i] - cnt[j + 1];
					if (num & 1) {
						ans += evensum + pre - j - 1;
					} else {
						ans += oddsum;
					}
					ans += n - zero;
				}
			}
			return ans;
		}
};
