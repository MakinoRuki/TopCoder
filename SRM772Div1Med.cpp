#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
class MaxPoints {
	public:
		void getsum(vector<pair<ll, int>>& rk, vector<ll>& sum) {
			int n = rk.size();
			int i = 0;
			ll tot=0;
			int cnt=0;
			while(i < n) {
				int j = i;
				for (j = i; j < n && rk[j].first == rk[i].first; ++j) {
					int id=rk[j].second;
					sum[id] += tot+(ll)cnt*(i == 0 ? 0 : (rk[j].first - rk[i-1].first));
				}
				tot += (ll)cnt * (i == 0 ? 0 : rk[i].first - rk[i-1].first);
				cnt += j-i;
				i = j;
			}
			i = n-1;
			tot=0;
			cnt=0;
			while(i >= 0) {
				int j = i;
				for (j = i; j >= 0 && rk[j].first == rk[i].first; --j) {
					int id=rk[j].second;
					sum[id] += tot+(ll)cnt*(i==n-1 ? 0 : (rk[i+1].first - rk[i].first));
				}
				tot += (ll)cnt*(i == n-1 ? 0 : rk[i+1].first-rk[i].first);
				cnt += i-j;
				i = j;
			}
		}
		int findMaxPoints(int n, vector<int> xg, vector<int> yg, ll k, int sx, int sy) {
			vector<ll> a,b;
			a.clear();
			b.clear();
		//	x.clear();
		//	y.clear();
			a.push_back(sx);
			vector<ll> sum(n+1, 0);
			for (int i = 1; i < n; ++i) {
				a.push_back((a.back() * 1103515245LL + 12345) % 2147483648LL);
			}
			//x = xg;
			vector<ll> x(xg.begin(), xg.end());
			for (int i = xg.size(); i < n; ++i) {
				x.push_back((a[i] % 2000001) - 1000000);
			}
			b.push_back(sy);
			for (int i =1; i < n; ++i) {
				b.push_back((b.back() * 1103515245LL + 12345) % 2147483648LL);
			}
			//y = yg;
			vector<ll> y(yg.begin(), yg.end());
			for (int i = yg.size(); i < n; ++i) {
				y.push_back((b[i] % 2000001) - 1000000);
			}
			vector<pair<ll, int>> rk;
			rk.clear();
			for (int i = 0; i < n; ++i) {
				rk.push_back(make_pair(x[i], i));
			}
		//	cout<<"aaa"<<endl;
			sort(rk.begin(), rk.end());
			getsum(rk, sum);
		//	cout<<"yyy"<<endl;
			rk.clear();
			for (int i = 0; i < n; ++i) {
				rk.push_back(make_pair(y[i], i));
			}
			sort(rk.begin(), rk.end());
			getsum(rk, sum);
			vector<ll> sr;
			sr.clear();
			for (int i = 0; i < n; ++i) {
				sr.push_back(sum[i]);
			}
			sort(sr.begin(), sr.end());
			ll cur=0;
			for (int i = 0; i < n; ++i) {
				cur -= sum[i];
			}
			cur /= 2;
			int i;
		//	cout<<"cur="<<cur<<endl;
			for (i = 0; i < n; ++i) {
				cur += sr[i];
				if (cur > k) {
					cur -= sr[i];
					break;
				}
			}
			if (cur > k) return -1;
			return i;
		}
};
