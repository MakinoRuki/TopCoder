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
#include <cmath>
#include <queue>
#define N 1000005
typedef long long ll;
using namespace std;
ll v1[N];
ll v2[N];
class NRooksPosition {
public:
	ll getminv(vector<pair<ll,ll>>& pts, int xy) {
		int n = pts.size();
		vector<ll> vs;
		vs.clear();
		for (int i = 0; i < pts.size(); ++i) {
			if (xy) vs.push_back(pts[i].second);
			else vs.push_back(pts[i].first);
		}
		sort(vs.begin(), vs.end());
		ll cur = 0LL;
		
		for (int i = 0; i < n; ++i) {
			cur += abs(vs[i]-i-vs[0]);
			v1[i+1] = vs[i]-i-vs[0];
		}
		sort(v1+1, v1+n+1);
		v2[0]=0LL;
		for (int i = 1; i <= n; ++i) {
			v2[i] = v2[i-1]+v1[i];
		}
		ll res = cur;
		ll det=0LL;
		for (int i = 1; i < n; ++i) {
	//		cout<<"i="<<i<<endl;
			ll det2=vs[i-1]-vs[i]+1;
			if (det2==0) {
				continue;
			}
			ll tmp=0LL;
			if (det2>0) {
				int lb,rb;
				int l=1,r=n+1;
				while(l<r) {
					int mid=(l+r)/2;
					if (v1[mid]+det>=0) {
						r = mid;
					} else {
						l = mid+1;
					}
				}
				rb = r;
				if (rb <= n) tmp += det2*(n-rb+1);
				l = 0, r=rb-1;
				while(l < r) {
					int mid=(l+r+1)/2;
					if (abs(v1[mid]+det) >= det2) {
						l = mid;
					} else {
						r=mid-1;
					}
				}
				lb = r;
				if (lb > 0) tmp -= det2*(lb);
				if (lb+1<=rb-1) {
					ll tmp2=v2[rb-1]-v2[lb]+det*(rb-1-lb);
					tmp -= abs(tmp2);
					tmp += det2*(rb-1-lb)+tmp2;
				}
			} else {
				int lb, rb;
				int l = 0, r = n;
				while(l<r) {
					int mid=(l+r+1)/2;
					if (v1[mid]+det<=0) {
						l = mid;
					} else {
						r=mid-1;
					}
				}
				lb = r;
				if (lb >0) tmp+=(-det2)*lb;
				l = lb+1;
				r = n+1;
				while(l<r) {
					int mid=(l+r)/2;
					if (v1[mid]+det+det2>=0) {
						r=mid;
					} else {
						l=mid+1;
					}
				}
				rb = r;
				if (rb<=n) tmp += det2*(n-rb+1);
				if (lb+1<=rb-1) {
					ll tmp2 = v2[rb-1]-v2[lb]+det*(rb-1-lb);
					tmp -= abs(tmp2);
					tmp += abs(det2*(rb-1-lb)+tmp2);
				}
			}
			cur += tmp;
			det += det2;
			res = min(res, cur);
		}
		return res;
	}
	ll minSteps(int n, vector<int> xpre, vector<int> ypre, int a, int b, int c) {
		vector<pair<ll,ll>> pts;
		pts.clear();
		int l = xpre.size();
		for (int i = 0; i < l; ++i) {
			pts.push_back(make_pair((ll)xpre[i], (ll)ypre[i]));
		}
		for (int i = l; i < n; ++i) {
		//	int sz=(int)pts.size();
			ll cx = ((ll)a * (ll)pts[i-1].first + (ll)b * (ll)pts[i-2].first) % (ll)c;
			ll cy = ((ll)a * (ll)pts[i-1].second + (ll)b * (ll)pts[i-2].second) % (ll)c;
			pts.push_back(make_pair(cx, cy));
		}
		ll tot=0LL;
	//	cout<<"ok"<<endl;
		tot += getminv(pts, 0);
	//	cout<<"ok1"<<" "<<tot<<endl;
	//	cout<<tot<<endl;
		tot += getminv(pts, 1);
		return tot;
	}
};
