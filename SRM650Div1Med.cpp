#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 2000
#define pi pair
#define mp make_pair
using namespace std;
bool removed[N][N];
bool notcut[N];
vector<int> edges[N];
vector<pi<int, int> > canRemoved;
bool vis[N];
class TheKingsRoadsDiv1 {
	public:
		int n, h;
		int addEdges;
		int node;
		int check (int root, int par) {
			node++;
			if (vis[root]) return -1;
			vis[root] = true;
			int cnt = 0;
			int lft = -1, rit = -1;
			for (int i = 0; i < edges[root].size(); ++i) {
				int v = edges[root][i];
				if (!removed[v][root] && v != par) {
					cnt++;
				}
			}
			if (cnt == 0) return 1;
			if (cnt != 2) return -1;
			for (int i = 0; i < edges[root].size(); ++i) {
				int v = edges[root][i];
				if (!removed[v][root] && v != par) {
					int tmp = check (v, root);
					if (tmp < 0) return -1;
					if (lft < 0) lft = tmp;
					else rit = tmp;
				}
			}
			if (lft == rit) return lft + 1;
			return -1;
		}
		bool isBinaryTree () {
			int cnt = 0;
			int root = -1;
			for (int i = 1; i <= n; ++i) {
				int valid = 0;
				for (int j = 0; j < edges[i].size(); ++j) {
					int v = edges[i][j];
					if (!removed[i][v]) {
						valid++;
					}
				}
				if (valid == 2) {
					cnt++;
					root = i;
				}
			}
			if (cnt == 0) return false;
			if (cnt > 1) return false;
			memset(vis, false, sizeof(vis));
			node = 0;
			int res = check (root, 0);
			if (res < 0) return false;
			if (res != h) return false;
			if (node != n) return false;
			return true;
		}
		bool dfs (int cur, int needRemove) {
			if (cur == canRemoved.size()) {
				if (needRemove) return false;
				if (isBinaryTree()) {
					return true;
				} return false;
			}
			if (needRemove == 0) {
				if (isBinaryTree()) {
					return true;
				}
				return false;
			}
			int u = canRemoved[cur].first;
			int v = canRemoved[cur].second;
			removed[u][v] = removed[v][u] = true;
			if (dfs (cur + 1, needRemove-1)) {
		 		return true; 
		 	}
			removed[u][v] = removed[v][u] = false;
			return dfs (cur + 1, needRemove); 
		}
		string solve () {
			canRemoved.clear();
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < edges[i].size(); ++j) {
					int v = edges[i][j];
					if (i < v && !notcut[i] && !notcut[v]) {
						canRemoved.push_back(mp(i, v));
					}
				}
			}
			if (canRemoved.size() > 70) return "Incorrect";
			memset(removed, false, sizeof(removed));
			if (dfs (0, addEdges)) return "Correct";
			return "Incorrect";  
		}
		string getAnswer (int _h, vector<int> a, vector<int> b) {
			h = _h;
			n = (1<<h) - 1;
			addEdges = 3;
			for (int i = 0; i < a.size(); ++i) {
				int j;
				for (j = 0; j < i; ++j) {
					if ((a[i] == b[j] && b[i] == a[j]) || (a[i] == a[j] && b[i] == b[j])) {
						break;
					}
				}
				if ((j < i) || (a[i] == b[i])) {
					addEdges--;
				} else {
					edges[a[i]].push_back(b[i]);
					edges[b[i]].push_back(a[i]);
				}
			}
			if (addEdges < 0) return "Incorrect";
			memset(notcut, false, sizeof(notcut));
			for (int i = 1; i <= n; ++i) {
				if (edges[i].size() == 1) {
					notcut[i] = true;
				}
			}
			for (int l = 1; l < h; ++l) {
				for (int i = 1; i <= n; ++i) {
					if (!notcut[i] && edges[i].size() <= 3) {
						int cnt = 0;
						for (int j = 0; j < edges[i].size(); ++j) {
							int v = edges[i][j];
							if (notcut[v]) {
								cnt++;
							}
						}
						if (cnt == 2) {
							notcut[i] = true;
						}
					}
				}
			}
			return solve();
		}
};
