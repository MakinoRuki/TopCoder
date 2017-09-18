#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define N 2002
using namespace std;
vector<int> edges[N];
bool vis[N];
vector<int> nedges[N][N];
int dis[N][N];
class JumpDistancesOnTree {
  public:
    int n;
    // make sure the dis is from set s.
    void dfs (int cur, int pre, int start, int ds) {
      dis[start][cur] = ds;
      nedges[start][ds].push_back(cur);
      for (int i = 0; i < edges[cur].size(); ++i) {
      	if (edges[cur][i] == pre) continue;
        dfs(edges[cur][i], cur, start, ds + 1);
      }
    }
    string isPossible (vector<int> p, vector<int> s) {
      n = p.size() + 1;
      for (int i = 0; i < p.size(); ++i) {
        edges[i + 1].push_back(p[i]);
        edges[p[i]].push_back(i + 1);
      }
      for (int i = 0; i < n; ++i) {
        dfs(i, -1, i, 0);
      }
      queue<int> Q;
      memset(vis, false, sizeof(vis));
      vis[0] = true;
      Q.push(0);
      while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < s.size(); ++i) {
          int d = s[i];
          for (int j = 0; j < nedges[cur][d].size(); ++j) {
            int nxt = nedges[cur][d][j];
            if (!vis[nxt]) {
              vis[nxt] = true;
              Q.push(nxt);
            }
          } 
        }
      }
      set<int> st;
      st.clear();
      for (int i = 0; i < s.size(); ++i) {
        st.insert(s[i]);
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i != j && vis[i] && vis[j]) {
            st.erase(dis[i][j]);
          }
        }
      }
      return st.empty() ? "Possible" : "Impossible";
    }
};
