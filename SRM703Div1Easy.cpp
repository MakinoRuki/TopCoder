#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class DAGConstruction {
  public:
    int n;
    vector<pii> pt;
    map<int, set<int> > re;
    vector<int> construct (vector<int> x) {
      n = x.size();
      pt.clear();
      re.clear();
      for (int i = 0; i < n; ++i) {
        pt.push_back(mp(x[i], i));
      }
      sort(pt.begin(), pt.end());
      vector<int> ans;
      ans.clear();
      for (int i = 0; i < pt.size(); ++i) {
        int v = pt[i].second;
        re[v].clear();
        re[v].insert(v);
        for (int j = i - 1; j >= 0; --j) {
          set<int> pre = re[pt[j].second];
          set<int> tmp;
          tmp.clear();
          for (set<int>::iterator itr  = pre.begin(); itr != pre.end(); ++itr) {
            tmp.insert(*itr);
          }
          for (set<int>::iterator itr = re[v].begin(); itr != re[v].end(); ++itr) {
            tmp.insert(*itr);
          }
          if (tmp.size() > pt[i].first) {
            continue;
          } else {
            for (set<int> ::iterator itr = pre.begin(); itr != pre.end(); ++itr) {
              re[v].insert(*itr);
            }
          }
        }
        if (re[v].size() != pt[i].first) {
          ans.clear();
          ans.push_back(-1);
          return ans;
        } else {
          for (set<int>::iterator itr = re[v].begin(); itr != re[v].end(); ++itr) {
            if ((*itr) != v) {
              ans.push_back(v);
              ans.push_back(*itr);
            }
          }
        }
      }
      return ans;
    }
};
