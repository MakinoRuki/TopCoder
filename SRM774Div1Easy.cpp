#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class LandSplitter {
  public:
    ll cheapest(int n, int a, int b) {
      ll x = n/b;
      ll y = n%b;
      ll ans = 0LL;
      if (y == 0 || y >= a) {
        ans = x * (ll)b * (ll)b + y * y;
        ans = ((ll)n * (ll)n - ans) / 2;
        //cout<<"ans="<<ans<<endl;
      } else {
        ll det1 = a-y;
        ll det2 = b-a;
        if (det2 == 0 || x == 0) return -1;
        ll x1 = (det1+det2-1) / det2;
        if (x1 > x) return -1;
        ll z3 = det1/det2;
        ll z2 = (det1%det2>0);
        ll z1 = x-z2-z3;
        ll w1 = (ll)b - det2;
        ll w2 = (ll)b - (det1 % det2);
      //  cout<<det1<<" "<<det2<<" "<<x1<<" "<<z3<<" "<<z2<<" "<<z1<<" "<<w1<<" "<<w2<<endl;
        ans = z1 * (ll)b * (ll)b + z2 * w2 * w2 + z3 * w1 * w1 + (ll)a * (ll)a;
        ans = ((ll)n*(ll)n-ans)/2;
      }
      return ans;
    }
};
