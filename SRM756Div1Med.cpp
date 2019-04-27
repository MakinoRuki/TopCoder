#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class CrazyCrazy {
	public:
		int n;
		string possible(string song) {
			n = song.size();
		//	vector<string> p1;
		//	vector<string> p2;
		//	p1.clear();
		//	p2.clear();
			unordered_set<string> st;
			st.clear();
			for (int i = 0; i < (1<<(n/2)); ++i) {
				string r1 = "";
				string r2 = "";
				for (int j = 0; j < n/2; ++j) {
					if ((1<<j) & i) {
						r1 += song[j];
					} else {
						r2 += song[j];
					}
				}
				if (r1.size() < r2.size()) swap(r1, r2);
				if (r1.substr(0, r2.size()) == r2) {
					//p1.push_back(r1.substr(r2.size()));
					st.insert(r1.substr(r2.size()));
				}
			}
			for (int i = 0; i < (1<<(n/2)); ++i) {
				string r1 = "";
				string r2 = "";
				for (int j = 0; j < n/2; ++j) {
					if ((1<<j) & i) {
						r1 += song[n/2+j];
					} else {
						r2 += song[n/2+j];
					}
				}
				if (r1.size() < r2.size()) swap(r1, r2);
				if (r1.substr(r1.size() - r2.size()) == r2) {
					string det = r1.substr(0, r1.size() - r2.size());
					//p2.push_back(det);
					if (st.find(det) != st.end()) return "possible";
				}
			}
			//cout<<p1.size()<<" "<<p2.size()<<endl;
		//	sort(p1.begin(), p1.end());
		//	sort(p2.begin(), p2.end());
		//	int j = 0;
		//	for (int i = 0; i < p1.size(); ++i) {
		//		while(j < p2.size() && p1[i] != p2[j]) j++;
		//		if (j < p2.size() && p1[i] == p2[j]) return "possible";
		//	}
			return "impossible";
		}
};
