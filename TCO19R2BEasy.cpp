#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class MedianFaking {
	public:
		int n;
		vector<int> minimize(int f, int m, vector<int> data, int g) {
			n = f * m;
			vector<int> rk;
			rk.clear();
			for (int i = 0; i < n; ++i) {
				rk.push_back(data[i]);
			}
			sort(rk.begin(), rk.end());
			int mid = (n-1)/2;
			if (rk[mid] < g) {
				map<int, int> cc;
				cc.clear();
				int X = 0;
				int Y = 0;
				for (int i = 0; i < n; ++i) {
					if (data[i] < g) {
						cc[i/m]++;
						Y++;
					}
				}
				vector<int> cc2;
				cc2.clear();
				for (auto ct = cc.begin(); ct != cc.end(); ++ct) {
					cc2.push_back(ct->second);
				}
				sort(cc2.begin(), cc2.end());
				Y -= (n-1)/2;
				int sum = 0;
				for (int i = cc2.size() - 1; i >= 0; --i) {
					if (sum < Y) {
						X++;
						sum += cc2[i];
					}
				}
				return {X, Y};
			}
			if (rk[mid] > g) {
				map<int, int> cc;
				cc.clear();
				int X = 0;
				int Y = 0;
				for (int i = 0; i < n; ++i) {
					if (data[i] > g) {
						cc[i/m]++;
						Y++;
					}
				}
				vector<int> cc2;
				cc2.clear();
				for (auto ct = cc.begin(); ct != cc.end(); ++ct) {
					cc2.push_back(ct->second);
				}
				sort(cc2.begin(), cc2.end());
				Y -= n/2;
			//	cout<<Y<<endl;
			//	for (auto ct = cc.begin(); ct != cc.end(); ++ct) {
			//		cout<<ct->first<<" "<<ct->second<<endl;
			//	}
				int sum = 0;
				for (int i = cc2.size() - 1; i >= 0; --i) {
					if (sum < Y) {
						X++;
						sum += cc2[i];
					}
				}
				return {X, Y};
			}
			return {0, 0};
		}
};
