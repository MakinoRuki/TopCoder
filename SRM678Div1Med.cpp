#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class TheEmpireStrikesBack {
	public:
		vector<pii> planets;
		vector<int> stack;
		bool check (int T, int m) {
			int cur = 0;
			int tot = 0;
			while (cur < stack.size()) {
				int i;
				for (i = cur; i < stack.size(); ++i) {
					pii p1 = planets[stack[cur]];
					pii p2 = planets[stack[i]];
					if (p2.first + T < p1.first || p2.second + T < p1.second) break;
				}
				tot++;
				cur = i - 1;
				while (i < stack.size()) {
					pii p1 = planets[stack[cur]];
					pii p2 = planets[stack[i]];
					if (p1.first + T < p2.first || p1.second + T < p2.second) break;
					i++;
				}
				cur = i;
			}
			return (tot <= m);
		}
		int find (int ax, int bx, int cx, int ay, int by, int cy, int n, int m) {
			planets.clear();
			stack.clear();
			planets.push_back(mp(ax, ay));
			for (int i = 1; i < n; ++i) {
				int px = planets.back().first;
				int py = planets.back().second;
				int nx = (int)(((ll)px * (ll)bx + cx) % mod);
				int ny = (int)(((ll)py * (ll)by + cy) % mod);
				planets.push_back(mp(nx, ny));
			}
			sort(planets.begin(), planets.end());
			for (int i = 0; i < n; ++i) {
				pii planet = planets[i];
				while (stack.size()) {
					pii tail = planets[stack.back()];
					if (planet.first >= tail.first && planet.second >= tail.second) {
						stack.pop_back();
					} else {
						break;
					}
				}
				stack.push_back(i);
			}
			int l = 0, r = 1000000000;
			while (l < r) {
				int T = (l + r) / 2;
				if (check(T, m)) r = T;
				else l = T + 1;
			}
			return r;
		}
};
