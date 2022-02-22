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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
int query(int l, int r) {
  while(l < r) {
    int mid = (l+r)/2;
    int mid2 = mid+1;
    printf("1 %d %d\n", mid, mid2);
    fflush(stdout);
    cin>>s;
    if (s == "TAK") {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  return r;
}
int main() {
  cin>>n>>k;
  int l = 1, r = n;
  int res = query(l, r);
  if (res > 1) {
    int res2 = query(1, res-1);
    printf("1 %d %d\n", res2, res);
    fflush(stdout);
    cin>>s;
    if (s == "TAK") {
      printf("2 %d %d\n", res2, res);
      fflush(stdout);
      return 0;
    }
  }
  int res2 = query(res+1, n);
  printf("2 %d %d\n", res, res2);
  fflush(stdout);
  return 0;
}
