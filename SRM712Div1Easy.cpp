//
//  SRM712Div1Easy.cpp
//  
//
//  Created by ruki on 5/29/17.
//
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
#define upper 1000000000000000LL
using namespace std;
typedef long long ll;
class LR {
public:
    int n;
    vector<ll> ss, tt;
    ll comb[N][N];
    ll sum[N][N];
    bool check (int tot, int l) {
        for (int i = 0; i < n; ++i) {
            ll tmp = ss[i];
            for (int ln = 1; ln <= l; ++ln) {
                if (ss[(i - ln + n) % n] <= upper && sum[ln - 1][l - 1] <= upper) {
                    ll tmp2 = ss[(i - ln + n) % n] * sum[ln - 1][l - 1];
                    if (tmp2 >= 0 && tmp2 <= upper) {
                        tmp += tmp2;
                    }
                }
            }
            for (int rn = 1; rn <= tot - l; ++rn) {
                if (ss[(i + rn) % n] <= upper && sum[rn - 1][tot - l - 1] <= upper) {
                    ll tmp2 = ss[(i + rn) % n] * sum[rn - 1][tot - l - 1];
                    if (tmp2 >= 0 && tmp2 <= upper) {
                        tmp += tmp2;
                    }
                }
            }
            if (tmp != tt[i]) return false;
        }
        return true;
    }
    string construct (vector<ll> s, vector<ll> t) {
        n = s.size();
        ss = s;
        tt = t;
        memset(comb, -1, sizeof(comb));
        memset(sum, -1, sizeof(sum));
        for (int i = 0; i <= 100; ++i) {
            comb[i][0] = 1LL;
            for (int j = 1; j <= i; ++j) {
                if (comb[i - 1][j] <= upper && comb[i - 1][j - 1] <= upper) {
                    if (comb[i - 1][j] + comb[i - 1][j - 1] <= upper) {
                        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                    }
                }
            }
        }
        for (int i = 0; i <= 100; ++i) {
            sum[i][i] = 1LL;
            for (int j = i + 1; j <= 100; ++j) {
                if (comb[j][i] <= upper && sum[i][j - 1] <= upper) {
                    if (sum[i][j - 1] + comb[j][i] <= upper) {
                        sum[i][j] = sum[i][j - 1] + comb[j][i];
                    }
                }
            }
        }
        for (int tot = 0; tot <= 100; ++tot) {
            for (int l = 0; l <= tot; ++l) {
                if (check(tot, l)) {
                    string ans = "";
                    for (int i = 0; i <= l; ++i) {
                        ans += "L";
                    }
                    for (int i = 0; i <= tot - l; ++i) {
                        ans += "R";
                    }
                    return ans;
                }
            }
        }
        return "No solution";
    }
};
