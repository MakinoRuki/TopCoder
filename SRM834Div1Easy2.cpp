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
#define eps 1e-10
#define M 200005
#define N 400
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
int id[30][20];
int par[N];
int res[N];
class MatchingPatterns {
public:
	int find(int x) {
		return x==par[x] ? x : par[x] = find(par[x]);
	}
	string solve(int n, vector<int> l, vector<string> ps) {
		vector<string> ps2;
		ps2.clear();
		int tot=0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < l[i]; ++j) {
				id[i][j] = tot++;
			}
		}
		for (int i = 0; i < 400; ++i) {
			par[i] = i;
			res[i] = -1;
		}
		vector<vector<int>> v;
		v.clear();
		for (int i = 0; i < ps.size(); ++i) {
			string tmp="";
			vector<int> tmp2;
			tmp2.clear();
			for (int j = 0; j < ps[i].size(); ++j) {
				if (ps[i][j] >= 'a' && ps[i][j] <= 'z') {
					tmp.push_back(ps[i][j]);
					tmp2.push_back(-1);
				} else {
					int id = ps[i][j]-'A';
					for (int k = 0; k < l[id]; ++k) {
						tmp.push_back(ps[i][j]);
						tmp2.push_back(k);
					}
				}
			}
			v.push_back(tmp2);
			ps2.push_back(tmp);
		}
		for (int i = 1; i < ps2.size(); ++i) {
			if (ps2[i].size() != ps2[0].size()) {
				return "";
			}
		}
		int sz = (int)ps2[0].size();
		string ans(sz, ' ');
		for (int j = 0; j < sz; ++j) {
			for (int i = 1; i < ps2.size(); ++i) {
				int id1 = ((ps2[0][j] >= 'a' && ps2[0][j] <= 'z') ? ps2[0][j]-'a' : 26 + id[ps2[0][j]-'A'][v[0][j]]);
				int p1 = find(id1);
				int id2 = ((ps2[i][j] >= 'a' && ps2[i][j] <= 'z') ? ps2[i][j]-'a' : 26 + id[ps2[i][j]-'A'][v[i][j]]);
				int p2 = find(id2);
				if (p1 != p2) {
					par[p2] = p1;
				}
			}
		}
		for (int i = 0; i < 400; ++i) {
			par[i] = find(i);
			if (i >= 0 && i < 26) {
				if (res[par[i]] >= 0 && res[par[i]] != i) {
					return "";
				}
				res[par[i]] = i;
			}
		}
		for (int j = 0; j < sz; ++j) {
			int id1 = ((ps2[0][j] >= 'a' && ps2[0][j] <= 'z') ? ps2[0][j]-'a' : 26 + id[ps2[0][j]-'A'][v[0][j]]);
			int p1 = find(id1);
			if (res[p1] < 0) ans[j] = 'a';
			else ans[j] = 'a' + res[p1];
		}
		return ans;
	}
};
