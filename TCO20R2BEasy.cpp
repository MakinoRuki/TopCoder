#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class FixedNumberOfDigits {
	public:
		ll pw[19];
		ll getds(ll s, ll t, ll st, ll d, int i) {
			if (s > t) return 0;
			ll l = (i == 1 ? 0 : pw[i-1]);
			ll r = pw[i]-1;
			if (t < l) return 0;
			if (s > r) return 0;
			ll a = (l < s ? 1 : (l-s+st-1)/st+1);
			ll b = min((r-s)/st+1, d);
			a = min(a, d);
			if (a <= b) return (b-a+1)*(ll)i;
			else return 0;
		}
		ll sum(int s, int t, ll nd) {
			pw[0] = 1LL;
			for (int i = 1; i <= 17; ++i) {
				pw[i] = pw[i-1]*10;
			}
			ll l = 1, r = 10000000000000000LL;
			while(l < r) {
				ll mid = (l+r)/2;
				ll tot=0LL;
		//		if (mid<8) cout<<"mid="<<mid<<endl;
				for (int i = 1; i <= 16; ++i) {
					tot += getds((ll)s, (ll)s+(ll)t * (mid-1), t, mid, i);
			//		if (mid==4) cout<<i<<" "<<getds((ll)s, (ll)s+(ll)t * (mid-1), t, mid, i)<<endl;
					if (tot >= nd) {
						break;
					}
				}
				if (tot >= nd) {
					r = mid;
				} else {
					l = mid+1;
				}
			}
			//cout<<"r="<<r<<endl;
			ll x = s;
			ll y = (ll)s+(ll)t*(r-2);
			ll tot=0LL;
			if (x <= y) {
			//cout<<"x="<<x<<" "<<y<<endl;
				for (int i = 1; i <= 16; ++i) {
					tot += getds(x, y, t, r-1, i);
		//			cout<<"i="<<i<<" "<<getds(x, y, t, r-1, i);
				}
			}
		//	cout<<"tot="<<tot<<endl;
			ll det = nd - tot;
			vector<int> dv;
			y = (ll)s+(ll)t*(r-1);
			if (y == 0) {
				dv.push_back(y);
			} else {
				while(y){
					dv.push_back(y%10);
					y/=10;
				}
			}
			int m = dv.size();
			ll res = 0LL;
			for (int i = 1; i <= det; ++i) {
				res = res*10 + dv[m-i];
			}
			return res;
		}
};
