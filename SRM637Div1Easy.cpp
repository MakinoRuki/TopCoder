#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class GreaterGame {
	public:
		int n;
		bool taken[N];
		double calc(vector<int> hand, vector<int> sothe) {
			n = hand.size();
			memset(taken, false, sizeof(taken));
			double ans = 0.0;
			vector<int> unknow;
			unknow.clear();
			sort(hand.begin(), hand.end());
			for (int i = 0; i < sothe.size(); ++i) {
				if (sothe[i] != -1) {
					int minv = 2 * n + 1;
					int idx = -1;
					int j;
					for (j = 0; j < hand.size(); ++j) {
						if (hand[j] >= sothe[i] && !taken[j]) {
							ans += 1.0;
							taken[j] = true;
							break;
						}
						if (!taken[j]) {
							if (hand[j] < minv) {
								minv = hand[j];
								idx = j;
							}
						}
					}
					if (j >= hand.size()) {
						taken[idx] = true;
					}
				}
			}
			for (int i = 1; i <= 2 * n; ++i) {
				bool found = false;
				for (int j = 0; j < hand.size(); ++j) {
					if (hand[j] == i) {
						found = true;
						break;
					}
				}
				for (int j = 0; j < sothe.size(); ++j) {
					if (sothe[j] == i) {
						found = true;
						break;
					}
				}
				if (!found) unknow.push_back(i);
			}
			for (int i = 0; i < unknow.size(); ++i) {
				for (int j = 0; j < hand.size(); ++j) {
					if (!taken[j] && hand[j] >= unknow[i]) {
						ans += 1.0 / (double)unknow.size();
					}
				}
			}
			return ans;
		}
};

/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 102
#define eps 1e-9
using namespace std;
class GreaterGame {
	public:
		bool vis[N];
		vector<int> sotheK, sotheU;
		double calc (vector<int> hand, vector<int> sothe) {
			double ans = 0.0;
			memset(vis, false ,sizeof(vis));
			int n = hand.size();
			sotheK.clear();
			sotheU.clear();
			for (int i = 0; i < n; ++i) { 
				if (sothe[i] != -1) {
					sotheK.push_back(sothe[i]);
				}
			}
			for (int i = 1; i <= 2 * n; ++i) {
				int j;
				for (j = 0; j < sotheK.size(); ++j) {
					if (sotheK[j] == i)
						break;
				}
				if (j >= sotheK.size()) {
					int k;
					for (k = 0; k < hand.size(); ++k) {
						if (hand[k] == i) {
							break;
						}
					}
					if (k >= hand.size()) {
						sotheU.push_back(i);
					}
				}
			}
			sort(hand.begin(), hand.end());
			sort(sotheU.begin(), sotheU.end());
			sort(sotheK.begin(), sotheK.end());
			for (int i = 0; i <= sotheK.size(); ++i) {
				double res = (double)i;
				if (i > 0) {
					int j;
					for (j = 0; j < hand.size(); ++j) {
						if (hand[j] > sotheK[i - 1] && !vis[j]) {
							vis[j] = true;
							break;
						}
					}
					if (j >= hand.size()) {
						break;
					}
				}
				double tmp = 0.0;
				int cnt = 0;
				for (int j = n - 1; j >= 0; --j) {
					if (vis[j])continue;
					cnt++;
					if (cnt > sotheU.size())
						break;
					for (int k = 0; k < sotheU.size(); ++k) {
						if (hand[j] > sotheU[k]) {
							tmp += 1.0;
						}
					}
				}
				if (sotheU.size()) {
					res += tmp / (double)sotheU.size();
				}
				if (res + eps > ans) {
					ans = res;
				}
			}
			return ans;
		}
};*/
