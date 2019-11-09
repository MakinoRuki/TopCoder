// dis用unordered_map会爆内存。
// pq用set会超时。因为遍历次数差不多，用set多了删除操作。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
class MahdiJumping {
	public:
		struct node {
			ll d;
			int u;
			bool operator < (const node& o) const {
				return d > o.d;
			}
		};
		ll minDis(int n, int A, int B, int a, int b) {
			vector<ll> dis(n, 1e18);
			priority_queue<node> pq;
			dis[0] = 0;
			node s;
			s.d = 0;
			s.u = 0;
			pq.push(s);
			while(!pq.empty()) {
				auto cur = pq.top();
				pq.pop();
				if (cur.u == n-1) return dis[n-1];
				if (cur.d != dis[cur.u]) continue;
				if (dis[cur.u+1] > cur.d+a) {
					dis[cur.u+1] = cur.d+a;
					node nxt=cur;
					nxt.u++;
					nxt.d += a;
					pq.push(nxt);
				}
				int v = (A*1LL*cur.u+B)%n;
				if (dis[v] > cur.d+b) {
					node nxt=cur;
					dis[v]=cur.d+b;
					nxt.u = v;
					nxt.d += b;
					pq.push(nxt);
				}
			}
			return dis[n-1];
		}
};
/*{5905, 643758, 1482867, 8072, 332}*/
