#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define N 100010
using namespace std;
typedef long long ll;
struct Node {
	unordered_set<int> idx;
	Node* next[2];
};
Node Trie[N * 20];
int top;
class MojisBag {
	public:
		ll X[N], Z[N];
		int inserted[N];
		int ans1, ans2;
		int ans;
		int cnt;
		vector<int> getds(int x) {
			vector<int> ds;
			ds.clear();
			int tmp = x;
			for (int i = 0; i < 10; ++i) {
				ds.push_back(tmp % 10);
				tmp /= 10;
			}
			reverse(ds.begin(), ds.end());
			return ds;
		}
		int find(Node* root, int cur, vector<int>& ds) {
			if (cur == 10) return *(root->idx).begin();
			if (root->next[ds[cur]^1]) {
				return find(root->next[ds[cur]^1], cur+1, ds);
			}
			return find(root->next[ds[cur]], cur+1, ds);
		}
		void insert(Node* root, int cur, vector<int>& ds, int iidx) {
			if (cur == 10) {
				(root->idx).insert(iidx);
				return;
			}
			if (!root->next[ds[cur]]) {
				root->next[ds[cur]]=&Trie[++top];
			}
			insert(root->next[ds[cur]], cur+1, ds, iidx);
		}
		int remove(Node* root, int cur, vector<int>& ds) {
			if (cur==10) {
				return (root->idx).size();
			}
			int res = remove(root->next[ds[cur]], cur+1, ds);
			if (res == 0) {
				if (!root->next[ds[cur]]->next[0] && !root->next[ds[cur]^1]->next[1]) {
					root->next[ds[cur]] = nullptr;
					top--;
				}
			}
			return res;
		}
		int maximumXor (int Q, int base, int add, int rate) {
			memset(inserted, -1, sizeof(inserted));
			top = 0;
			ans1 = -1;
			ans2 = -1;
			ans = 0;
			X[0] = add;
			cnt = 0;
			if (X[0] % rate != 0) {
				vector<int> ds=getds(X[0]);
				insert(&Trie[0], 0, ds, 0);
				inserted[0] = 0;
				cnt++;
			}
			Z[0] = 0;
			for (int i = 1; i < Q; ++i) {
				X[i] = (X[i-1] * base + add) % 1000000007;
				if (X[i] % rate != 0) {
					vector<int> ds = getds(X[i]);
					int res = find(&Trie[0], 0, ds);
					if (ans1 < 0 || (X[res]^X[i])>ans) {
						ans1=res;
						ans2=i;
						ans = X[res]^X[i];
					}
					insert(&Trie[0], 0, ds, i);
					inserted[cnt] = i;
					cnt++;
				} else {
					int ridx = X[i] % cnt;
					if (inserted[ridx] == -1) continue;
					vector<int> ds = getds(X[inserted[ridx]]);
					int num = remove(&Trie[0], 0, ds);
					if (num == 0 && (X[inserted[ridx]] == X[ans1] || X[inserted[ridx]] == X[ans2])) {
						for (int k = 0; k < 10 * (i + 1); ++k) {
							Trie[k].idx.clear();
							Trie[k].next[0] = nullptr;
							Trie[k].next[1] = nullptr;
						}
						ans1 = -1;
						ans2 = -1;
						ans = 0;
						inserted[ridx] = -1;
						top=0;
						for (int k = 0; k < cnt; ++k) {
							if (inserted[k] < 0) continue;
							vector<int> ds = getds(X[inserted[k]]);
							int res = find(&Trie[0], 0, ds);
							if (ans1 < 0 || (X[res]^X[inserted[k]])>ans) {
								ans1=res;
								ans2=inserted[k];
								ans = X[res]^X[inserted[k]];
							}
							reverse(ds.begin(), ds.end());
							insert(&Trie[0], 0, ds, inserted[k]);
						}
					} 
				}
				ll Y = (ans1 < 0 ? 0 : ans);
				Z[i] = (Z[i - 1] * base + Y) % 1000000007;
			}
			return Z[Q - 1];
		}
};
