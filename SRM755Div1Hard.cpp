#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define N 200005
using namespace std;
typedef long long ll;
struct node {
  int l, r;
  ll pre;
  ll sum;
}segtree[N*4];
ll V[N];
void init(int root, int l, int r) {
  segtree[root].l = l;
  segtree[root].r = r;
  if (l == r) {
    segtree[root].pre = V[l];
    segtree[root].sum = V[l];
    return;
  }
  int m = (r+l)/2;
  init(root*2+1, l, m);
  init(root*2+2, m+1, r);
  segtree[root].sum = segtree[root*2+1].sum+segtree[root*2+2].sum;
  segtree[root].pre = max(segtree[root].pre, segtree[root*2+1].pre);
  segtree[root].pre = max(segtree[root].pre, segtree[root*2+1].sum+segtree[root*2+2].pre);
}
void update(int root, int pos, int val) {
  if (segtree[root].l == segtree[root].r) {
    segtree[root].pre = val;
    segtree[root].sum = val;
    return;
  }
  int m = (segtree[root].l+segtree[root].r)/2;
  if (pos<=m) update(root*2+1, pos, val);
  else update(root*2+2, pos, val);
  segtree[root].sum = segtree[root*2+1].sum+segtree[root*2+2].sum;
  segtree[root].pre = max(segtree[root*2+1].pre, segtree[root*2+1].sum+segtree[root*2+2].pre);
}
class DejaVu {
  public:
    ll A[N], M[N];
    int nxt[N];
    int mostDejaVus(int n, int seed, int r) {
      unordered_map<ll, pair<int, int> > num;
      num.clear();
      A[0] = seed;
      for (int i = 1; i < n; ++i) {
        A[i]=(A[i-1]*1664525LL + 1013904223LL) % 4294967296LL;
      }
      for (int i = 0; i <= n; ++i) {
        nxt[i] = n;
      }
      for (int i = 0; i < n; ++i) {
        M[i] = A[i] % r;
       // cout<<i<<" "<<M[i]<<endl;
        if (num.find(M[i])== num.end()) {
          num[M[i]] = make_pair(1, i);
        } else {
          auto cur = num[M[i]];
          int cnt = cur.first;
          int pos = cur.second;
          nxt[pos] = i;
          cnt++;
          num[M[i]] = make_pair(cnt, i);
        }
        if (num[M[i]].first == 2) V[i] = 1;
        else if (num[M[i]].first == 3) V[i] = -1;
        else V[i] = 0;
      }
      init(0, 0, n-1);
      ll ans = segtree[0].pre;
      for (int i = 0; i < n; ++i) {
     //   V[i] = 0;
      //  update(0, i, 0);
        int n1 = nxt[i];
        if (n1 < n) {
          update(0, n1, 0);
          V[n1] = 0;
        }
        int n2 = nxt[n1];
        if (n2 < n) {
          update(0, n2, 1);
          V[n2] = 1;
        }
        int n3 = nxt[n2];
        if (n3 < n) {
          update(0, n3, -1);
          V[n3] = -1;
        }
        ans = max(ans, segtree[0].pre);
      }
      return ans;
    }
};
