#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200020
using namespace std;
typedef long long ll;
struct node {
	int l, r;
	int v;
}tree[N<<2];
class SmoothPermutations {
public:
	void build(int idx, int l, int r, int m) {
		if (l == r) {
			tree[idx].l = l;
			tree[idx].r = r;
			tree[idx].v = l % m;
			return;
		}
		int mid = (l+r)/2;
		build(idx*2, l, mid, m);
		build(idx*2+1, mid+1, r, m);
		tree[idx].v = (long)tree[idx*2].v * (long)tree[idx*2+1].v % m;
	}
	long query(int idx, int l, int r, int m) {
		if (tree[idx].l == l && tree[idx].r == r) {
			return tree[idx].v % m;
		}
		int mid = (tree[idx].l+tree[idx].r) / 2;
		if (r <= mid) return query(idx*2, l, r, m);
		else if (l > mid) return query(idx*2+1, l, r, m);
		else return query(idx*2, l, mid, m) * query(idx*2+1, mid+1, r, m) % m;
	}
	long countPermutations(int t, int m, int mx, int seed, vector<int> prefN, vector<int> prefK, vector<int> prefX) {
		int A[3*t];
		A[0] = seed;
		for (int i = 1; i < 3 * T; ++i) {
			A[i] = (A[i-1] * 1103515245 + 12345) % 2147483648;
		}
		build(1, 1, mx, m);
		int len = prefN.size();
		long ans=0;
		int n, k, x;
		for (int i = 0; i < len; ++i) {
			n = prefN[i];
			k = prefK[i];
			x = prefX[i];
			ans += query(1, 1, n-k, m) * query(1, x - k + 1, x, m) % m;
		}
		for (int i = len; i < t; ++i) {
			n = (A[i] % mx) + 1;
			k = (A[t+ i] % n) +1;
			x = (A[2 * t+i] % n) + 1;
			ans += query(1, 1, n-k, m) * query(1, x-k+1, x, m) % m;
		}
		return ans;
	}
};
