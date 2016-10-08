#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define N 1002
using namespace std;
typedef long long ll;
class FromToDivisible {
	public:
		int m;
		map<int, int> dis;
		// 离散化。把b[i]作为顶点BFS。
		int shortest (int n, int s, int t, vector<int> a, vector<int> b) {
			m = a.size();
			queue<int> Q;
			dis.clear();
			for (int i = 0; i < m; ++i) {
				if (s % a[i] == 0) {
					if (dis.find(b[i]) == dis.end()) {
						dis[b[i]] = 1;
						Q.push(b[i]);
					}
				}	
			}
			while (!Q.empty()) {
				int cur = Q.front();
				Q.pop();
				if (t % cur == 0) return dis[cur];
				for (int i = 0; i < m; ++i) {
					ll lcm = (ll)cur * (ll)a[i] / (ll)__gcd(cur, a[i]);
					if (lcm <= n) {
						if (dis.find(b[i]) == dis.end()) {
							dis[b[i]] = dis[cur] + 1;
							Q.push(b[i]);
						}
					}
				}
			}
			return -1;
		}
};
