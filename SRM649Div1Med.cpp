#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
class XorSequence {
	public:
		vector<int> a;
		int getBits (int number) {
			int cnt = 0;
			while (number != 1) {
				cnt++;
				number /= 2;
			}
			return cnt;
		}
		ll getmax(int n, int sz, int a0, int a1, int p, int q, int r) {
			a.clear();
			a.push_back(a0);
			a.push_back(a1);
			int bits = getBits(n);
			for (int i = 2; i < sz; ++i) {
				int tmpa = ((ll)a[i - 2] * (ll)p + (ll)a[i - 1] * (ll)q + (ll)r) % n;
				a.push_back(tmpa); 
			}
			ll ans = 0LL;
			for (int i = bits; i >= 1; --i) {
				map<int, vector<int> > prefix;
				prefix.clear();
				for (int j = 0; j < sz; ++j) {
					prefix[a[j] >> i].push_back((a[j] >> (i - 1)) & 1);
				}
				ll sum1 = 0LL, sum0 = 0LL;
				for (map<int, vector<int> > ::iterator itr = prefix.begin(); itr != prefix.end(); ++itr) {
					vector<int> numbers = itr->second;
					ll n1 = 0LL, n0 = 0LL;
					for (int j = numbers.size() - 1; j >= 0; --j) {
						if (numbers[j] == 0) {
							n0++;
							sum0 += n1;
						} else {
							n1++;
							sum1 += n0;
						}
					}
				}
				ans += max(sum0, sum1);
			}
			return ans;
		}
};
