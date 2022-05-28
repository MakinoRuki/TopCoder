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
#define eps 1e-10
#define M 200005
#define N 2502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dp1[N][N];
int dp2[N];
vector<pair<string, string>> cc = {{"E","."},{"T", "-"},
	{"A",".-"},
{"B","-..."},
{"C","-.-."},
{"D","-.."},

{"F","..-."},
{"G","--."},
{"H","...."},
{"I",".."},
{"J",".---"},
{"K","-.-"},
{"L",".-.."},
{"M","--"},
{"N","-."},
{"O","---"},
{"P",".--."},
{"Q", "--.-"},
{"R", ".-."},
{"S", "..."},

{"U", "..-"},
{"V", "...-"},
{"W", ".--"},
{"X", "-..-"},
{"Y", "-.--"},
{"Z", "--.."},
};
class MorseCodeCorrector {
public:
	int calc(string& ms, int l, int r) {
		int len=r-l+1;
		int res = inf;
		for (int i = 0; i < cc.size(); ++i) {
			if (cc[i].second.size() == len) {
				int sum=0;
				for (int j = 0; j < len; ++j) {
					if (ms[l+j] != cc[i].second[j]) {
						sum++;
					}
				}
				res=min(res, sum);
			}
		}
		return res;
	}
	string getss(string& ms, int l, int r, int x) {
		int len = r-l+1;
		for (int i = 0; i < cc.size(); ++i) {
			if (cc[i].second.size() == len) {
				int sum=0;
				for (int j = 0; j < len; ++j) {
					if (ms[l+j] != cc[i].second[j]) {
						sum++;
					}
				}
				if (sum == x) {
					return cc[i].second;
				}
			}
		}
	}
	string getans(string& ms, int l, int r) {
		string tmp="";
	//	cout<<"x="<<calc(ms,12,15)<<" "<<dp1[17][29]<<" "<<dp1[12][29]<<endl;
		while(l <= r) {
		//	cout<<"lr="<<l<<" "<<r<<endl;
			for (int i = l; i < l + 4; ++i) {
				if (i < r) {
					if (i+1 < r) {
						int add = 0;
						if (ms[i+1] != '|') add++;
						int x = calc(ms, l, i);
						//if (l == 12 && i == 15 && dp1[])
						if (x + add + dp1[i+2][r] == dp1[l][r]) {
						//	cout<<"x1="<<i<<endl;
							tmp += getss(ms, l, i, dp1[l][i]) + "|";
							l = i+2;
							break;
						}
					}
				} else {
					int x = calc(ms, l, r);
					if (x == dp1[l][r]) {
					//	cout<<"x2="<<i<<endl;
						tmp += getss(ms, l, r, dp1[l][r]);
						l = r+1;
						break;
					}
				}
			}
		}
		reverse(tmp.begin(), tmp.end());
		return tmp;
	}
	string fix(string ms) {
		int n = (int)ms.size();
		for (int i = 0; i <= n; ++i) {
			dp2[i] = inf;
			for (int j = 0; j <= n; ++j) {
				dp1[i][j] = inf;
				
			}
		}
		for (int i = n-1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				for (int k = 0; k < 4; ++k) {
					if (i+k == j || i+k+1 < j) {
						int res = dp1[i][i+k];
						if (i + k+1 < j) {
							if (ms[i+k+1] != '|') {
								res++;
							}
							res += dp1[i+k+2][j];
						} else {
							res = calc(ms, i, i+k);
						}
						dp1[i][j] = min(dp1[i][j], res);
					}
				}
			}
		}
		dp2[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (dp2[i] < inf) {
				if (i > 0) {
					//int res = inf;
					int add =0;
					if (ms[i] != '|') add++;
					if (i+1<n && ms[i+1] != '|') add++;
					if (i + 3 <= n) {
						for (int j = i+3; j <= n; ++j) {
							dp2[j] = min(dp2[j], dp2[i] + add + dp1[i+2][j-1]);
						}
					}
				} else {
					for (int j = i+1; j <= n; ++j) {
						dp2[j] = min(dp2[j], dp1[i][j-1]);
					}
				}
			}
		}
		//int ans = dp2[n];
	//	cout<<"ans="<<calc(ms, 0, 3)<<" "<<dp1[0][3]<<" "<<ans<<endl;
		string anss = "";
		int cur = n;
		while(cur) {
			int i;
		//	cout<<"cur="<<cur<<endl;
			for (i = cur; i > 0; --i) {
				int add = 0;
				if (i > 1) {
					if (i-3>=1) {
						if (ms[i-2] != '|') add++;
						if (ms[i-3] != '|') add++;
						if (dp2[i-3] < inf && dp2[i-3] + add + dp1[i-1][cur-1] == dp2[cur]) {
						//	cout<<"i1="<<i<<endl;
							anss += getans(ms, i-1, cur-1) + "||";
							cur = i-3;
							break;
						}
					}
				} else {
					if (dp1[i-1][cur-1] == dp2[cur]) {
					//	cout<<"i2="<<i<<endl;
						anss += getans(ms, i-1, cur-1);
						cur = i-1;
						break;
					}
				}
			}
		}
		reverse(anss.begin(), anss.end());
		return anss;
	}
};
