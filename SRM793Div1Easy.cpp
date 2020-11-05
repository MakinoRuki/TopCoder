#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class GoldMining {
	public:
		ll getcost(ll d, ll tot, ll det, ll t, ll hc) {
			ll c1=det;
			if ((tot+d)<=det/t) {
				c1=(tot+d)*t;
			}
			ll c2=det;
			if (tot<=det/t) {
				c2=tot*t;
			}
			c1 -= c2;
			if (c1<0) return 0;
			if (hc<=c1/d) {
				return c1-d*hc;
			}
			return 0;
		}
		ll maxProfit(ll gg, ll mt, ll hc) {
			ll tot=1;
			ll cur=0;
			ll cur2=0;
			for (int i = 1; i <= mt; ++i) {
				ll det=gg-cur2;
				ll x=det/(mt-i+1);
				ll num=cur/hc;
				if (tot + num <= x) {
					if (mt-i+1>hc) {
						cur -= hc*num;
						tot += num;
					}
				} else {
					ll c0=0;
					ll num2=0;
					if (num>0) {
						ll cc = getcost(num, tot, det, mt-i+1, hc);
						if (cc>c0) {
							c0=cc;
							num2=num;
						}
					}
					if (x-tot>0) {
						ll c1=getcost(x-tot, tot, det, mt-i+1, hc);
						if (c1>c0) {
							c0=c1;
							num2=x-tot;
						}
					}
					if (x+1-tot>0) {
						ll c2=getcost(x+1-tot, tot, det, mt-i+1, hc);
						if (c2>c0) {
							c0=c2;
							num2=x+1-tot;
						}
					}
					if (c0>0) {
						cur -= num2*hc;
						tot += num2;
					}
				}
				ll det2=max(0LL, gg-cur2);
				cur += min(det2, tot);
				cur2 += min(det2, tot);
				if (cur>gg) cur=gg;
				if (cur2>gg) cur2=gg;
			}
			return cur;
		}
};
