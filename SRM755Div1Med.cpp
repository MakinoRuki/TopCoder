#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 505
using namespace std;
typedef long long ll;
class OneHandRoadPainting {
  public:
    int n;
    ll fastest(vector<int>ds, vector<int>de, int pb) {
      n = ds.size();
      ll ans = 0;
      ll pre = 0;
      for (int i = n - 1; i >= 0; --i) {
      	if (pre >= de[i]-ds[i]) {
      		pre -= de[i]-ds[i];
      		continue;
      	}
      	ll q = (de[i]-ds[i]-pre)/pb;
      	ll r = (de[i]-ds[i]-pre)%pb;
      	ans += pb*q*(1LL+q);
      	ll a = ds[i]+r;
      	ans += 2LL*q*a;
      	if (r) ans += 2LL*a;
      	if (r) pre = pb-r;
      	else pre = 0;
      }
      return ans;
    }
};
