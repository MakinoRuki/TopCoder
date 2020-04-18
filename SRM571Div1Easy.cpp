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
#define N 52
using namespace std;
typedef long long ll;
class FoxAndMp3 {
public:
	ll pw[12];
	string getstr(int x) {
		string res="";
		while(x) {
			res.push_back((x%10)+'0');
			x /= 10;
		}
		reverse(res.begin(), res.end());
		return res + ".mp3";
	}
	string getres(int n, int x) {
		string res="";
		vector<int> ds;
		ds.clear();
		int m = n;
		while(m) {
			ds.push_back(m%10);
			m /= 10;
		}
		reverse(ds.begin(), ds.end());
		int ok = 0;
		ll last[12];
		memset(last, 0, sizeof(last));
		for (int i = 1; i <= ds.size(); ++i) {
			last[i] = last[i-1] + pw[i-1]*ds[ds.size()-i];
		}
	//	if (x==19) cout<<last[3]<<endl;
		while(true) {
			int d;
			if (res.empty()) {
				for (d=1; d <= 9; ++d) {
					ll sum=0LL;
					for (int j = 0; j < ds.size()-res.size()-1; ++j) {
						sum += pw[j];
					}
					int rem = ds.size()-res.size()-1;
					if (ok<0 || (ok==0 && d<ds[res.size()])) {
						sum += pw[rem];
					} else if (ok==0 && d==ds[res.size()]) {
						sum += last[rem]+1;
					}
					if (sum >= x) break;
					x -= sum;
				}
			} else {
				x--;
				if (x == 0) return res+".mp3";
				for (d = 0; d <= 9; ++d) {
					ll sum=0LL;
					for (int j = 0; j < ds.size()-res.size()-1; ++j) {
						sum += pw[j];
					}
					int rem = ds.size()-res.size()-1;
					if (ok<0 || (ok==0 && d<ds[res.size()])) {
						sum += pw[rem];
					} else if (ok==0 && d == ds[res.size()]) {
						sum += last[rem]+1;
					}
					if (sum >= x) break;
					x -= sum;
				}
			}
			res.push_back('0'+d);
			if (ok==0) {
				if (d<ds[res.size()-1]) ok=-1;
				else if (d>ds[res.size()-1]) ok=1;
			}
			//ok |= (d<ds[res.size()-1]);
		}
		return res+".mp3";
	}
	vector<string> playList(int n) {
		vector<string> ans;
		ans.clear();
		pw[0] =1LL;
		for (int i = 1; i <= 10; ++i) {
			pw[i] = pw[i-1]*10LL;
		}
		if (n <= 50) {
			for (int i = 1; i <= n; ++i) {
				ans.push_back(getstr(i));
			}
			sort(ans.begin(), ans.end());
		} else {
			for (int i = 1; i <= 50; ++i) {
				ans.push_back(getres(n, i));
			}
		}
		//cout<<getres(n, 19)<<endl;
		return ans;
	}
};
