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
typedef long long ll;
using namespace std;
class AtLeastKDays {
public:
	int n;
	const ll inf = (1LL<<60)-1;
	ll ans[52][52];
	int mm;
	void calc(vector<string>& c, int md) {
		ll res[n+1][n+1];
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				res[i][j] = (i==j ? 0 : inf);
			}
		}
		ll cs[n+1][n+1];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i==j) cs[i][j] = inf;
				else cs[i][j] = c[i][j]-'0';
			}
		}
		int md2=md;
		while(md) {
			if (md & 1) {
				ll res2[n+1][n+1];
				for (int i = 0; i < n; ++i){
					for (int j = 0; j < n; ++j) {
						res2[i][j]=inf;
					}
				}
				for (int k = 0; k < n; ++k) {
					for (int i = 0; i < n; ++i){ 
						for (int j = 0; j < n; ++j) {
							if (cs[i][k]<inf && res[k][j]<inf) {
							//	cout<<"z="<<k<<" "<<i<<" "<<j<<" "<<cs[i][k]<<" "<<res[k][j]<<endl;
								res2[i][j]=min(res2[i][j], cs[i][k]+res[k][j]);
							}
						}
					}
				}
				for (int i= 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						res[i][j]=res2[i][j];
					}
				}
			}
			ll cs2[n+1][n+1];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cs2[i][j] = inf;
				}
			}
			for (int k= 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (cs[i][k]<inf && cs[k][j]<inf) {
							cs2[i][j]=min(cs2[i][j], cs[i][k]+cs[k][j]);
						}
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j= 0; j < n; ++j) {
					cs[i][j]=cs2[i][j];
				}
			}
			md /= 2;
		}
		if (md2 >= mm) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (res[i][j] < inf) {
					//	if (md2==1) cout<<i<<" "<<j<<" "<<res[i][j]<<endl;
						ans[i][j]=min(ans[i][j], res[i][j]);
					}
				}
			}
		}
	}
	ll sumOfMinCosts(vector<string> c, int md) {
		n = c.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans[i][j] = inf;
			}
		}
		mm=md;
		for (int i = md; i <= md+n; ++i) {
			calc(c, i);
		}
		ll tot=0LL;
		for (int i = 0; i < n;++i) {
			for (int j = 0; j < n; ++j) {
				tot += ans[i][j];
			}
		}
		return tot;
	}
};
