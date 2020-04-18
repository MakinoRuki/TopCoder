#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define N 52
using namespace std;
typedef long long ll;
class RobotHerb {
public:
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	int n;
	void solve(vector<int>& a, ll& x, ll& y, int& d, int t) {
		//int n = a.size();
		for (int i = 0; i <t; ++i) {
			for (int j = 0; j < n; ++j) {
				x += dx[d]*a[j];
				y += dy[d]*a[j];
				d = (d+a[j])%4;
			}
		}
		//cout<<x<<" "<<y<<" "<<d<<endl;
	}
	ll getdist(int t, vector<int> a) {
		n = a.size();
		ll x=0, y=0;
		int d=0;
		solve(a, x, y, d, 1);
		if (d == 0) {
			return t*(abs(x)+abs(y));
		}
		if (d == 2) {
			if (t%2 == 0) return 0;
			return abs(x)+abs(y);
		}
		t %= 4;
	//	cout<<"t="<<t<<endl;
		//if (t==0) return 0;
		x = 0, y = 0;
		d = 0;
	//	cout<<"x="<<x<<" "<<"y="<<y<<" "<<"d="<<d<<endl;
		solve(a, x, y, d, t);
		return abs(x)+abs(y);
	}
};
