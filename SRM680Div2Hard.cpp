#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SZ 17
using namespace std;
bool dp[2][SZ][SZ][SZ];
class BearFair2 {
  public:
    int q;
    vector<int> query;
    string isFair(int n, int b, vector<int> upTo, vector<int> quantity) {
      q = upTo.size();
      query.clear();
      for (int i = 0; i < q; ++i) {
        query.push_back(mp(upTo[i], quantity[i]));
      }
      sort(query.begin(), query.end());
      for (int i = 1; i < q; ++i) {
        if (query[i].first == query[i - 1].first && query[i].second != query[i - 1].second) {
          return "unfair";
        }
      }
      if (query.back().first == b) {
        if (query.back().second != n) return "unfair";
      } else {
        query.push_back(mp(b, n));
        q++;
      }
      memset(dp, false, sizeof(dp));
      dp[0][0][0][0] = true;
      int now = 0;
      for (int i = 0; i < q; ++i) {
        memset(dp[now ^ 1], false, sizeof(dp[now ^ 1]));
        for (int a = 0; a <= n / 3; ++a) {
          for (int b = 0; b <= n / 3; ++b) {
            for (int c = 0; c <= n / 3; ++c) {
              if (dp[now][a][b][c]]) {
                int delta = (i == 0 ? query[i].first : query[i].first - query[i - 1].first);
                int cnt = (i == 0 ? query[i].second : query[i].second - query[i - 1].second);
                vector<int> nums(3, delta / 3);
                int r = (i == 0 ? 0 : query[i - 1].first % 3);
                for (int d = 1; d <= (delta % 3); ++d) {
                  nums[(r + d) % 3]++;
                }
                for (int na = 0; na <= min(cnt, nums[0]); ++na) {
                  for (int nb = 0; nb <= min(cnt, nums[1]); ++nb) {
                    int nc = cnt - na - nb;
                    if (na > 3 / n || nb > n / 3 || nc > n / 3) continue;
                    if (nc >= 0 && nc <= nums[2]) {
                      dp[now ^ 1][a + na][b + nb][c + nc] = true;
                    }
                  }
                }
              }
            }
          }
        }
        now ^= 1;
      }
      return dp[q & 1][n / 3][n / 3][n / 3] ? "fair" : "unfair";
    }
};
