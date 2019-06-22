#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
class AddPeriodic {
	public:
		void getf(string s, ll& u, ll& d) {
			ll pw[15];
			pw[0]=1;
			for (int i = 1; i <= 12; ++i) {
				pw[i]=pw[i-1]*10;
			}
			int n = s.size();
			int ok = 0;
			ll r1 = 0;
			ll r2 = 0;
			for (int i = 0; i < n; ++i) {
				if (s[i] >= '0' && s[i] <= '9') {
					if (ok == 1) u++;
					else if (ok == 2) d++;
				} else {
					if (s[i] == '.') ok=1;
					else if (s[i] == '(') ok =2;
				}
				if (s[i] >= '0' && s[i] <= '9') {
					r1 = r1 * 10 + s[i]-'0';
					if (ok == 0 || ok == 1) {
						r2 = r2 *10 + s[i]-'0';
					}
				}
			}
			d = pw[u+d]-pw[u];
			u = r1 - r2;
		}
		string add(string a, string b) {
			ll au = 0, ad = 0;
			getf(a, au, ad);
			ll bu = 0, bd = 0;
			getf(b, bu, bd);
			//cout<<au<<" "<<ad<<endl;
			//cout<<bu<<" "<<bd<<endl;
			ll cu = au * bd + bu * ad;
			ll cd = ad * bd;
			//cout<<cu<<" "<<cd<<endl;
			string res = to_string(cu / cd);
			res += ".";
			cu %= cd;
			map<ll, int> m;
			m.clear();
			while(true) {
				if (m.find(cu) != m.end()) {
					int idx = m[cu];
					res.insert(idx, "(");
					res += ")";
					break;
				}
				m[cu] = res.size();
				cu *= 10;
				ll r = cu / cd;
				res += to_string(r);
				cu %= cd;
			}
			return res;
		}
};
