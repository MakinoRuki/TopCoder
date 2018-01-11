#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class OnlySanta {
	public:
		int n;
		bool hassub(string s, string x) {
			int j = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (j == x.size()) return true;
				if (s[i] == x[j]) j++;
			}
			return j == x.size();
		}
		string solve(string s) {
			n = s.size();
			if (hassub(s, "SATA")) {
				int i;
				int si = -1, ai = -1;
				for (i = 0; i < n; ++i) {
					if (s[i] == 'S' && si < 0) si = i;
					if (s[i] == 'A' && si >= 0 && ai < 0) ai = i;
				}
			//	cout<<ai<<" "<<si<<endl;
				s = s.substr(0, ai + 1) + "N" + s.substr(ai + 1, n - ai - 1);
			} else if (hassub(s, "SAT")) {
				int si = -1, ai = -1, ti = -1;
				for (int i = 0; i < n; ++i) {
					if (s[i] == 'S' && si < 0) si = i;
					if (s[i] == 'A' && si >= 0 && ai < 0) ai = i;
					if (s[i] == 'T' && ai >= 0 && ti < 0) ti = i;
				}
				string ts = s;
				string tmp = "";
				if (ti < n - 1) tmp = s.substr(ti + 1, n - ti - 1);
				s = s.substr(0, ai + 1) + "N" + s.substr(ai + 1, ti - ai) + "A" + tmp;
				if (hassub(s, "SATAN")) {
					int ni = n - 1;
					for (ni = n - 1; ni >= 0; --ni) {
						if (ts[ni] == 'N') break;
					}
					tmp = "";
					if (ni < n - 1) tmp = ts.substr(ni + 1, n - 1 - ni);
					s = ts.substr(0, ni + 1) + "TA" + tmp;
				}
			} else {
				s = s + "SANTA";
			}
			return s;
		}
};
