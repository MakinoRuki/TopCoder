#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll maxv[N][N][N];
ll minv[N][N][N];
class ClassicTowers {
	public:
		int n;
		ll getmax(int A, int B, int C) {
			if (maxv[A][B][C] >= 0) return maxv[A][B][C];
			if (A + B + C == 0) return 0;
			ll res = -1;
			// 枚举最大disk是哪根柱子
			if (A) res = max(res, getmax(A - 1, C, B) + 1 + getmax(A + B + C - 1, 0, 0));
			if (B) res = max(res, getmax(B - 1, C, A) + 1 + getmax(A + B + C - 1, 0, 0));
			if (C) res = max(res, getmax(A, B, C - 1));
			maxv[A][B][C] = res;
			return res;
		}
		ll getmin(int A, int B, int C) {
			if (minv[A][B][C] >= 0) return minv[A][B][C];
			if (A + B + C == 0) return 0;
			ll res = 1LL << 60;
			// 枚举最大disk是哪根柱子
			if (A) res = min(res, getmin(A - 1, C, B) + 1 + getmin(0, A + B + C - 1, 0));
			if (B) res = min(res, getmin(B - 1, C, A) + 1 + getmin(A + B + C - 1, 0, 0));
			if (C) res = min(res, getmin(A, B, C - 1));
			minv[A][B][C] = res;
			return res;
		}
		string find (int A, int B, int C, string a, string b, string c, ll k) {
			if (A < 0 || B < 0 || C < 0) return string(51, 'z');
			if (A + B + C == 0 && k == 0) return "";
			if (k < getmin(A, B, C) || k > getmax(A, B, C)) return string(51, 'z');
			string res = string(51, 'z');
			int tot = A + B + C;
			// 枚举最大disk是哪根柱子
			if (res.size() > tot) res = find(A - 1, C, B, a, c, b, k - (1LL << (tot - 1))) + a;
			if (res.size() > tot) res = find(B - 1, C, A, b, c, a, k - (1LL << (tot - 1))) + b;
			if (res.size() > tot) res = find(A, B, C - 1, a, b, c, k) + c;
			return res;
		}
		string findTowers(ll k, vector<int> count) {
			n = count[0] + count[1] + count[2];
			string res = string(51, 'z');
			memset(maxv, -1, sizeof(maxv));
			memset(minv, -1, sizeof(minv));
			if (res.size() > n) res = find(count[0], count[1], count[2] - 1, "A", "B", "C", k) + "C";
			if (res.size() > n) res = find(count[1], count[0], count[2] - 1, "B", "A", "C", k) + "C";
			if (res.size() > n) res = find(count[0], count[2], count[1] - 1, "A", "C", "B", k) + "B";
			if (res.size() > n) res = find(count[2], count[0], count[1] - 1, "C", "A", "B", k) + "B";
			if (res.size() > n) res = find(count[1], count[2], count[0] - 1, "B", "C", "A", k) + "A";
			if (res.size() > n) res = find(count[2], count[1], count[0] - 1, "C", "B", "A", k) + "A";
			if (res.size() > n) res = "";
			return res;
		}
};
