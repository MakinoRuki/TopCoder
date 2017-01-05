#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class TreeDistanceConstruction {
  public:
    int n;
    int vis[N];
    vector<pii> rank;
    int cnt[N];
    vector<int> construct (vector<int> d) {
      n = d.size();
      int maxd = 0;
      vector<int> ans;
      ans.clear();
      rank.clear();
      memset(cnt, 0, sizeof(cnt));
      for (int i = 0; i < n; ++i) {
        maxd = max(maxd, d[i]);
        rank.push_back(mp(d[i], i));
        cnt[d[i]]++;
      }
      sort(rank.begin(), rank.end());
      int up = maxd;
      int down = (maxd + 1) / 2;
      if (maxd & 1) {
        for (int i = up; i >= down; --i) {
          if (cnt[i] < 2) {
            return ans;
          }
          if (i == down && cnt[i] != 2) return ans;
        }
        for (int i = 0; i < down; ++i) {
          if (cnt[i]) return ans;
        }
        vector<int> tmp;
        tmp.clear();
        for (int i = up; i >= down; --i) {
          for (int j = 0; j < n; ++j) {
            if (d[j] == i && !vis[j]) {
              tmp.push_back(j);
              vis[j] = true;
              break;
            }
          }
        }
        for (int i = 0; i < tmp.size() - 1; ++i) {
          ans.push_back(tmp[i]);
          ans.push_back(tmp[i + 1]);
        }
        tmp.clear();
        for (int i = up; i >= down; --i) {
          for (int j = 0; j < n; ++j) {
            if (d[j] == i && !vis[j]) {
              tmp.push_back(j);
              vis[j] = true;
              break;
            }
          }
        }
        for (int i = 0; i < tmp.size() -1; ++i) {
          ans.push_back(tmp[i]);
          ans.push_back(tmp[i  +1]);
        }
        bool find = false;
        for (int i = 0; i < n; ++i) {
          if (find) break;
          for (int j=0;j<n; ++j) {
            if (i != j && d[i] == down && d[j] == down) {
              ans.push_back(i);
              ans.push_back(j);
              find= true;
              break;
            }
          }
        }
        for (int i = 0; i < n; ++i) {
          if (!vis[i] ) {
            for (int j = 0; j < n; ++j) {
              if (i != j && d[i] ==d[j]+1 && vis[j]) {
                ans.push_back(i);
                ans.push_back(j);
                vis[i] = true;
                break;
              }
            }
          }
        }
      } else {
        for (int i = up; i >= down; --i) {
          if (i == down && cnt[i] != 1) return ans;
          if (i > down && cnt[i] < 2) return ans;
        }
        for (int i = 0; i < down; ++i) {
          if (cnt[i]) return ans;
        }
        cout<<"ok"<<endl;
        vector<int> tmp;
        tmp.clear();
        for (int i = up; i>down; --i) {
          for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] == i) {
              tmp.push_back(j);
              vis[j] = true;
              break;
            }
          }
        }
        for (int i = 0; i < tmp.size() -1; ++i) {
          ans.push_back(tmp[i]);
          ans.push_back(tmp[i + 1]);
        }
        tmp.clear();
        for (int i = up; i > down; --i) {
          for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] == i) {
              tmp.push_back(j);
              vis[j] = true;
              break;
            }
          }
        }
        for (int i = 0; i < tmp.size() - 1; ++i) {
          ans.push_back(tmp[i]);
          ans.push_back(tmp[i+1]);
        }
        for (int i = 0; i <n ; ++i) {
          if (d[i] == down) {
            for (int j = 0; j < n; ++j) {
              if (d[j] == d[i] + 1) {
                ans.push_back(i);
                ans.push_back(j);
                vis[i]=true;
                vis[j]=true;
              }
            }
            break;
          }
        }
        for (int i = 0; i <n ;++i) {
          if (!vis[i]) {
            for (int j = 0; j < n; ++j) {
              if (d[j] + 1 == d[i] && vis[j]) {
                ans.push_back(i);
                ans.push_back(j);
                vis[i] = true;
                break;
              }
            }
          }
        }
      }
      return ans;
    }
};
