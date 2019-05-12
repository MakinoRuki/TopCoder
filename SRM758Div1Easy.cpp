#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class SelfDescFind {
  public:
    int n;
    string ans = "";
    void dfs(int cur, vector<int>& ds, vector<int>& cnt) {
      if (cur == n) {
        vector<int>num(10, 0);
        bool vis[10];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; ++i) {
          num[cnt[i]]++;
          num[ds[i]]++;
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          if (num[ds[i]] != cnt[i]) {
            ok = false;
          }
          vis[ds[i]]=true;
        }
        for (int i = 0; i < 10; ++i) {
          if (!vis[i] && num[i]) {
            ok=false;
            break;
          }
        }
        if (ok) {
          vector<pair<int, int> > rk;
          rk.clear();
          for (int i = 0; i < n; ++i) {
            rk.push_back(make_pair(cnt[i], ds[i]));
          }
          sort(rk.begin(), rk.end());
          string res="";
          for (int j = 0; j < rk.size(); ++j) {
            res+=to_string(rk[j].first);
            res+=to_string(rk[j].second);
          }
          if (ans.empty()) ans = res;
          else ans = min(ans, res);
        }
        return;
      } else {
        if (ds[cur] == 0) {
          cnt.push_back(1);
          dfs(cur+1, ds, cnt);
        } else {
          int ub = 3;
          if (ds[cur] == 1) ub=9;
          for (int i = 1; i <= ub; ++i) {
            cnt.push_back(i);
            dfs(cur+1, ds, cnt);
            cnt.pop_back();
          }
        }
      }
    }
    string construct(vector<int> ds) {
      n = ds.size();
      vector<int> cnt;
      cnt.clear();
      dfs(0, ds, cnt);
      return ans;
    }
};
