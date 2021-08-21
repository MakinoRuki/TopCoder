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
#define eps 1e-7
#define M 52
#define N 40000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
bool pm[N];
int p[N];
class SmoothDivisors {
public:
	int calc(int a, int b) {
		int cnt=0;
	//	if (x>=1) cnt++;
		for (int i = a; i <= b; ++i) {
			if (!pm[i]) {
				int p1 = p[i];
				int c1=0;
				int y = i;
				while(y%p1==0) {
					y/=p1;
					c1++;
				}
			//	if (i == 47 || i == 48 || i == 49) cout<<"y="<<i<<" "<<y<<endl;
				if (y == 1) {
					continue;
				}
				//	if (i == 47 || i == 48 || i == 49) cout<<"c="<<i<<" "<<c1<<endl;
				if (c1 > 2) {
					continue;
				}
				if (c1 == 2) {
					if (pm[y]) cnt++;
				} else {
					if (pm[y]) cnt++;
					else {
						int qr = (int)sqrt(y);
						if (qr*qr == y && pm[qr]) {
							cnt++;
						}
					}
				}
			}
		}
		return b-a+1-cnt;
	}
	int count(int a, int b) {
		for (int i = 1; i <= b; ++i) {
			pm[i] = true;
			p[i] = i;
		}
		for (int i = 2; i <= b; ++i) {
			if (pm[i]) {
				for (ll j = (ll)i*(ll)i; j <= (ll)b; j+=i) {
					if (pm[j]) {
						p[j] = i;
					}
					pm[j] = false;
				}
			}
		}
	//	cout<<calc(b)<<" "<<calc(a-1)<<endl;
		return calc(a,b);
	}
};
