#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 50002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll seq1[22][N], seq2[N];
ll good[N], bad[N];
ll pw[N];
class DivFree {
  public:
  	int getLog (int k) {
  		int res = 0;
  		while (k) {
  			res++;
  			k /= 2;
  		}
  		return res;
  	}
    int dfcount(int n, int k) {
      int log_k = getLog(k);
      memset(seq1, 0, sizeof(seq1));
      memset(seq2, 0, sizeof(seq2));
      for (int i = 1; i <= k; ++i) {
        seq1[1][i] = 1LL;
        seq2[1]++;
        if (seq2[1] >= mod) seq2[1] -= mod;
      }
      pw[0] = 1LL;
      for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * (ll)k % mod;
      }
      for (int i = 1; i <= log_k; ++i) {
        for (int j = 1; j <= k; ++j) {
          for (int p = j * 2; p <= k; p += j) {
            seq1[i + 1][p] = (seq1[i + 1][p] + seq1[i][j]) % mod;
          }
        }
        for (int j = 1; j <= k; ++j) {
          seq2[i + 1] = (seq2[i + 1] + seq1[i + 1][j]) % mod;
        }
      }
      good[0] = 1;
      good[1] = k;
      for (int i = 2; i <= n; ++i) {
        bad[i] = (bad[i] + bad[i - 1] * (ll)k % mod) % mod;
        for (int l = 2; l <= min(log_k, i); ++l) {
          if (l & 1) {
            bad[i] = (bad[i] - good[i - l] * seq2[l] % mod + mod) % mod;
          } else {
            bad[i] = (bad[i] + good[i - l] * seq2[l] % mod) % mod;
          }
        }
        good[i] = (pw[i] - bad[i] + mod) % mod;
      }
      return good[n];
    }
};
