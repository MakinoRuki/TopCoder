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
class GuessForMoney {
public:
	double balance(ll n) {
		double tot = 0;
		int pw = 0;
		ll sum = 0LL;
		ll m = n;
		while((1LL<<pw) <= n) {
			sum += (1LL<<pw);
			tot += (double)(pw+1) * (double)(1LL<<pw);
			n -= (1LL<<pw);
			pw++;
			//cout<<pw<<" "<<tot<<" "<<n<<endl;
		}
		tot += (double)(pw+1) * (double)n;
		double ans = tot / (double)m;
		return ans;
	}
};
