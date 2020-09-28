#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class BicycleLock {
  public:
    string makeDistinct(vector<int> ds) {
      bool vis[10];
      memset(vis, false, sizeof(vis));
      vis[ds[0]]=true;
      string ans="";
      for (int i = 1; i < ds.size(); ++i) {
        ans += ">";
        int j;
        for (j = 0; j < 10; ++j) {
          if (!vis[j]) {
            break;
          }
        }
        vis[j]=true;
        int det=(j-ds[i]+10)%10;
        if (det>0) {
          for (int j = 0; j < det; ++j) {
            ans += "+";
          }
        }
      }
      return ans;
    }
};
