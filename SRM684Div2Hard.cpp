#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class Autohamil {
  public:
    int n;
    bool dis[N][N];
    // Start from point 0, visit all the points. What is the positive condition ? Every pair connects !!
    string check(vector<int> z0, vector<int> z1) {
      n = z0.size();
      memset(dis, false, sizeof(dis));
      for (int i = 0; i < n; ++i) {
        dis[i][z0[i]] = true;
        dis[i][z1[i]] = true;
      }
      for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            dis[i][j] = dis[i][j] || (dis[i][k] && dis[k][j]);
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        if (i != 0 && !dis[0][i]) return "Does not exist";
        for (int j = 0; j < n; ++j) {
          if (i == j) continue;
          if (!(dis[i][j] || dis[j][i])) return "Does not exist";
        }
      }
      return "Exists";
    }
};
