// Status number is O(n). At most 2 new status will be added after each round.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define pll pair<int, ll>
#define mp make_pair
using namespace std;
typedef long long ll;
map<pll, double> pr;
class JanuszInTheCasino {
	public:
		double findProbability (ll n, int m, int k) {
			pr.clear();
			pr[mp(0, n)] = 1.0;
			for (int i = 0; i < k; ++i) {
				while (pr.size()) {
					pll cur = (pr.begin())->first;
					if (cur.first < i) {
						pr.erase(cur);
					} else {
						break;
					}
				}
				for (map<pll, double>::iterator itr = pr.begin(); itr != pr.end(); ++itr) {
					if (itr->first.first > i) break;
					ll j = itr->first.second;
					ll q = j / m;
					ll r = j % m;
					pr[mp(i + 1, j - q)] += (double)(m - r) / (double)m * pr[mp(i, j)];
					if (r) {
						pr[mp(i + 1, j - q - 1)] += (double)r / (double)m * pr[mp(i, j)];
					}
				}
			}
			return 1.0 - pr[mp(k, 0)];
		}
};
