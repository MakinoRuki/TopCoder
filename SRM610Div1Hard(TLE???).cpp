#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
//typedef long long ll;
class MiningGoldHard {
public:
	int interpolate(long x1, long y1, long x2, long y2, long x0) {
		return (int)((x0-x1)*(y2-y1)/(x2-x1)+y1);
	}
	void cut(vector<int>& x, vector<int>& y, int n) {
		vector<int> nx, ny;
		nx.clear();
		ny.clear();
		auto point = [&nx, &ny](int px, int py) {
			nx.push_back(px);
			ny.push_back(py);
		};
		for (int i = 0; i < x.size(); ++i) {
			if (x[i] >= 0 && x[i] <= n) {
				point(x[i], y[i]);
			}
			if (i + 1 < x.size() && (0 > x[i] && 0 < x[i+1])) {
				point(0, interpolate(x[i], y[i], x[i+1], y[i+1], 0));
			}
			if (i + 1 < x.size() && (n > x[i] && n < x[i+1])) {
				point(n, interpolate(x[i], y[i], x[i+1], y[i+1], n));
			}
		}
		x = nx;
		y = ny;
	}
	void expand(vector<int>& x, vector<int>& y, int d) {
		int bi = 0;
		for (int i = 0; i < x.size(); ++i) {
			if (y[i] > y[bi]) {
				bi = i;
			}
		}
		vector<int> nx, ny;
		nx.clear();
		ny.clear();
		auto point = [&nx, &ny](int px, int py) {
			nx.push_back(px);
			ny.push_back(py);
		};
		for (int i = 0; i <= bi; ++i) {
			point(x[i]-d, y[i]);
		}
		if (d != 0) {
			point(x[bi]+d,y[bi]);
		}
		for (int i = bi+1; i < x.size(); ++i) {
			point(x[i]+d, y[i]);
		}
		x = nx;
		y = ny;
	}
	void add(vector<int>& x, vector<int>& y, int n, int e) {
		vector<int> nx, ny;
		nx.clear();
		ny.clear();
		auto point = [&nx, &ny, &n, &e](int px, int py) {
			nx.push_back(px);
			ny.push_back(py + n - abs(px-e));
		};
		for (int i = 0; i < x.size(); ++i) {
			point(x[i], y[i]);
			if (i + 1 < x.size() && (e > x[i] && e < x[i+1])) {
				point(e, interpolate(x[i], y[i], x[i+1], y[i+1], e));
			}
		}
		x = nx;
		y = ny;
	}
	int solve(int n, vector<int>& e, vector<int>& d) {
		int m = e.size();
		vector<int> x, y;
		x = {0, n};
		y = {0, 0};
		for (int i = m - 1; i >= 0; --i) {
			add(x, y, n, e[i]);
			if (i > 0) {
				expand(x, y, d[i - 1]);
				cut(x, y, n);
			}
		}
		return *max_element(y.begin(), y.end());
	}
	int GetMaximumGold(int n, int m, vector<int> ei, vector<int> ej, vector<int> di, vector<int> dj) {
		int ans = solve(n, ei, di);
		ans += solve(m, ej, dj);
		return ans;
	}
};
