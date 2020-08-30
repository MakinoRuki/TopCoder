#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class ThreeDigits {
	public:
		ll getr(ll a, ll b, ll c) {
			ll res=1LL;
			while(b) {
				if (b&1) res=res*a%c;
				a=a*a%c;
				b/=2;
			}
			return res;
		}
		bool check(ll a, ll b, ll c) {
			if (a==0 || a ==1) return a < c;
			ll res=1LL;
			for (int i = 1; i <= b; ++i) {
				res *= a;
				if (res >= c) return false;
			}
			return true;
		}
		string calculate(int x, int y, int z) {
			ll a = x;
			ll b = y;
			ll c = z;
			ll r = getr(a, b, 1000LL*c);
			ll res= r*1000LL/c;
			string ans="";
			for (int i = 0; i < 6; ++i) {
				int d = res%10;
				res/=10;
				ans.push_back(d+'0');
				if (i==2) ans+=".";
			}
			if (check(a, b, 1000LL*c) && ans.back()=='0') {
				ans.pop_back();
			}
			if (check(a,b,1000LL*c) && ans.back()=='0') {
				ans.pop_back();
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
		
};
