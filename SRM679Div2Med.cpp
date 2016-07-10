#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define mp make_pair
#define pii pair<int, int>
using namespace std;
class ContestScoreboard {
  public:
    int n;
    map<string, vector<pii> > submits;
    map<string, int> idx;
    vector<int> times;
    vector<int> findWinner (vector<string> scores) {
      n = scores.size();
      vector<int> ans(n, 0);
      set<int> tmp;
      tmp.clear();
      vector<string> names;
      for (int i = 0; i < n; ++i) {
        bool isName = true;
        bool isScore = true;
        string name = "";
        int score = 0, time = 0;
        int m = scores[i].size();
        for (int j = 0; j < m; ++j) {
          if (isName) {
            if (scores[i][j] != ' ') {
              name += " ";
              name[name.size() - 1] = scores[i][j];
            } else {
              isName = false;
              idx[name] = i;
              names.push_back(name);
            }
          } else {
            if (scores[i][j] == '/') {
              isScore = false;
            } else if (scores[i][j] == ' ') {
              isScore = true;
              submits[name].push_back(mp(score, time));
              tmp.insert(time);
              score = 0, time = 0;
            } else {
              if (isScore) {
                score = score * 10 + scores[i][j] - '0';
              } else {
                time = time * 10 + scores[i][j] - '0';
              }
            }
          }
        }
        submits[name].push_back(mp(score, time));
        tmp.insert(time);
      }
      for (set<int>::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
        times.push_back(*itr);
      }
      sort(names.begin(), names.end());
      ans[idx[names[0]]] = 1;
      for (int i = 0; i < times.size(); ++i) {
        int D = times[i];
        vector<pair<int, string> > rank;
        rank.clear();
        for (int j = 0; j < n; ++j) {
          int tot = 0;
          for (int k = 0; k < submits[names[j]].size(); ++k) {
            if (submits[names[j]][k].second <= D) {
              tot += submits[names[j]][k].first;
            }
          }
          rank.push_back(mp(-tot, names[j]));
        }
        sort(rank.begin(), rank.end());
        ans[idx[rank[0].second]] = 1;
      }
      return ans;
    }
};
