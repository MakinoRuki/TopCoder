#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
class RectangularObstacle {
	public:
		ll countReachable(int x1, int x2, int y1, int y2, int s) {
			ll tot=(ll)(s+2)*(ll)(s+1)/2-2LL*(ll)(s+1)+1;
			tot = tot*4LL;
			tot += 4LL*(ll)s+1LL;
			ll cnt=0LL;
			//cout<<"tot="<<tot<<endl;
			for (int x = x1; x <= x2; ++x) {
				ll y = (ll)s-(ll)abs(x);
				if (y < y1) continue;
				if (y <= y2) cnt += (ll)y-(ll)y1+1;
				else {
					cnt += (ll)y-(ll)y1+1;
					ll my = max((ll)s-(ll)abs(x1-1)+(ll)x1-1LL-(ll)x, (ll)s+(ll)x-2LL*(ll)(x2+1));
					//cout<<"my="<<my<<endl;
					if (my > y2) {
						cnt -= my-y2;
					}
				}
			}
			return tot-cnt;
		}
};
