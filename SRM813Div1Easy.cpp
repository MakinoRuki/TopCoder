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
#define M 72
#define N 40000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
bool pm[N];
int p[N];
vector<int> edges[M];
int deg[M];
int getx(char c) {
	if (c >= '0' && c <= '9') {
		return c-'0';
	}
	if (c >= 'a' && c <= 'z') {
		return c-'a' + 10;
	}
	return c - 'A' + 36;
}
char gety(int x) {
	if (x >= 0 && x <= 9) {
		return '0' + x;
	}
	if (x >= 10 && x <= 35) {
		return x-10 + 'a';
	}
	return x-36 + 'A';
}
class PartialRaceResults {
public:
	string reconstruct(vector<string>& mem) {
		set<int> ss;
		ss.clear();
		for (int i = 0; i < 70; ++i) {
			edges[i].clear();
		}
		// set<pair<int,int>> es;
		// es.clear();
		// for (int i = 0; i < mem.size(); ++i) {
		// 	int x = getx(mem[i][0]);
		// 	int y = getx(mem[i][2]);
		// 	int z = getx(mem[i][3]);
		// 	es.insert(make_pair(y, x));
		// 	es.insert(make_pair(x, z));
		// }
		// memset(deg, 0, sizeof(deg));
		// for (auto pr : es) {
		// 	int x = pr.first;
		// 	int y = pr.second;
		// 	edges[x].push_back(y);
		// 	deg[y]++;
		// 	ss.insert(x);
		// 	ss.insert(y);
		// }
		for (int i = 0; i < mem.size(); ++i) {
			int x = getx(mem[i][0]);
			int y = getx(mem[i][2]);
			int z = getx(mem[i][3]);
			edges[y].push_back(x);
			deg[x]++;
			edges[x].push_back(z);
			deg[z]++;
			ss.insert(x);
			ss.insert(y);
			ss.insert(z);
		}
		queue<int> q;
		for (int i = 0; i < 70; ++i) {
			if (ss.find(i) != ss.end() && deg[i] == 0) {
				q.push(i);
			}
		}
		string ans="";
		while(!q.empty()) {
			int cur=q.front();
			q.pop();
			ans.push_back(gety(cur));
			for (int i = 0; i < edges[cur].size(); ++i) {
				int v = edges[cur][i];
				deg[v]--;
				if (deg[v] == 0) {
					q.push(v);
				}
			}
			// set<int> s2;
			// s2.clear();
			// for (int i = 0; i < edges[cur].size(); ++i) {
			// 	int v = edges[cur][i];
			// 	s2.insert(v);
			// }
			// for (auto v : s2) {
			// 	deg[v]--;
			// 	if (deg[v] == 0) {
			// 		q.push(v);
			// 	}
			// }
		}
		if (ans.size() != ss.size()) {
			return "";
		}
		return ans;
	}
};
