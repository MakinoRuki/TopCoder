#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class CardboardBoxes {
  public:
    ll count(ll s) {
      if (s%2!=0) return 0;
      s /= 2;
      ll ans = 0LL;
      for (ll x = 2; x * x <= s; ++x) {
        if (s % x == 0) {
          ans += min(x/2, s/x-1);
          if (s/x != x) {
            ans += min((s/x)/2, x-1);
          }
        }
      }
      return ans;
    }
};
