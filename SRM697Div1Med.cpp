#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
struct node {
	int bits[2] = {-1, -1};
	int count;
}trie[N * 32];
int top;
class XorOrderDiv1 {
	public:
		int a[N]; 
		ll tot;
		void trieInsert (int idx, int bit, int num) {
			while (bit >= 0) {
				int cur = (num & (1<<bit)) > 0;
				if (trie[idx].bits[cur] < 0) {
					trie[idx].bits[cur] = ++top;
				}
				idx = trie[idx].bits[cur];
				trie[idx].count++;
				bit--;
			}
		}
		void trieSearch (int idx, int bit, int num) {
			while (bit >= 0) {
				int cur = (num & (1<<bit)) > 0;
				if (trie[idx].bits[cur ^ 1] >= 0) {
					int cnt = trie[trie[idx].bits[cur ^ 1]].count;
					tot = (tot + (ll)cnt * (ll)cnt) % mod;
				}
				idx = trie[idx].bits[cur];
				bit--;
			}
		}
		int get(int m, int n, int a0, int b) {
			top = 0;
			ll ans = 0LL;
			a[0] = a0 % (1LL << m);
			trieInsert(0, m - 1, a[0]);
			for (int i = 1; i < n; ++i) {
				a[i] = (a[i - 1] + (ll)b) % (1LL << m);
				//a[i] = (int)(((ll)a0 + (ll)i * (ll)b) % mod);
				trieInsert(0, m - 1, a[i]);
			}
			for (int i = 0; i < n; ++i) {
				tot = 0LL;
				trieSearch(0, m - 1, a[i]);
				ll tmp = 0LL;
				if (m >= 2) {
					tmp = ((ll)(n - 1) * (ll)(n - 1) % mod - tot + mod) % mod;
					tmp = tmp * (1LL << (m - 2)) % mod;
				}
				tmp = (tmp + tot * (1LL << (m - 1)) % mod) % mod;
				ans = ans ^ tmp;
				//ans = (ans + tmp) % mod;
			}
			return (int)ans;
		}
};
