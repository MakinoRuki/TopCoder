// a/b小数部分四舍五入的做法是(a+b/2)/b。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;
typedef long long ll;
class EllysTicketPrices {
	public:
		double getPrice(int n, vector <int> c, int tar) {
			tar *= 100;
			ll l = 1, r = tar *n *2;
			while(l < r) {
				ll m = (l+r)/2;
				ll sum = m, mr = m;
			//    cout<<m<<" "<<getrd(m)<<endl;
			//	cout<<0<<" "<<res<<endl;
				for (int i = 0; i < c.size(); ++i) {
					mr = (mr * (100 +c[i]) + 50)/100;
					sum += mr;
				//	cout<<i+1<<" "<<p<<" "<<getrd(p)<<endl;
				}
				if ((2LL * sum + n)/ (2LL*n) < tar) {
					l = m + 1;
				} else {
					r = m;
				}
			}
			return (double)r/100.0;
		}
};
