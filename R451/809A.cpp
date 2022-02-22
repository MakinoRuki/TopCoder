#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 202
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) {
      res = res * x % mod;
    }
    x=x*x%mod;
    y /= 2;
  }
  return res;
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  sort(a+1, a+n+1);
  ll tot=0LL;
  for (int i = 1; i < n; ++i) {
    ll tmp = (getpw(2LL, n-i) - 1 + mod) % mod;
    tmp = (ll)a[i] * tmp % mod;
    tot = (tot - tmp + mod) % mod;
  }
  for (int i = n; i > 1; --i) {
    ll tmp = (getpw(2LL, i-1) - 1 + mod) % mod;
    tmp = (ll)a[i] * tmp % mod;
    tot = (tot + tmp) % mod;
  }
  cout<<tot<<endl;
  return 0;
}
