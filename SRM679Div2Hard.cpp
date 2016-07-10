#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 102
#define M 2005
#define inf 1000000000
using namespace std;
class ForbiddenStreets {
  public:
    int m;
    set<int> path[N][N];
    int dis[N][N];
    set<int> setIntersection (set<int> & a, set<int> & b) {
    	set<int> res;
    	res.clear();
    	for (set<int>::iterator itr = a.begin(); itr != a.end(); ++itr) {
    		if (b.find(*itr) != b.end()) {
    			res.insert(*itr);
    		}
    	}
    	return res;
    }	
    set<int> setUnion (set<int> & a, set<int> & b) {
    	set<int> res;
    	res.clear();
    	for (int x : a) {
    		res.insert(x);
    	}
    	for (int y : b) {
    		res.insert(y);
    	}	
    	return res;
    }
    vector<int> find (int n, vector<int> A, vector<int> B, vector<int> time) {
      m = A.size();
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dis[i][j] = (i == j ? 0 : inf);
        }
      }
      for (int i = 0; i < m; ++i) {
        dis[A[i]][B[i]] = dis[B[i]][A[i]] = time[i];
        path[A[i]][B[i]].insert(i);
        path[B[i]][A[i]].insert(i);
      }
      for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (dis[i][j] > dis[i][k] + dis[k][j]) {
              dis[i][j] = dis[i][k] + dis[k][j];
              path[i][j] = setUnion(path[i][k], path[k][j]);
            } else if (dis[i][j] == dis[i][k] + dis[k][j]) {
              set<int> res = setUnion(path[i][k], path[k][j]);
              path[i][j] = setIntersection(path[i][j], res);
            }
          }
        }
      }
      vector<int> ans(m, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (set<int>::iterator itr = path[i][j].begin(); itr != path[i][j].end(); ++itr) {
            ans[*itr]++;
          }
        }
      }
      return ans;
    }
};
