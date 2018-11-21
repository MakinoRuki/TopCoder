#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define eps 1e-6
using namespace std;
class RadioRange {
	public:
		int n;
		double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
			n = X.size();
			vector<pair<double, double> > c;
			c.clear();
			for (int i = 0; i < n; ++i) {
				double d = (double)X[i] * (double)X[i] + (double)Y[i] * (double)Y[i];
				double minr = sqrt(d) - (double)R[i];
				if (minr < eps) minr = 0.0;
				double maxr = sqrt(d) + (double)R[i];
				c.push_back(make_pair(minr, maxr));
			}
			sort(c.begin(), c.end());
			double tot = 0.0;
			int i = 0;
			double begin = 0.0;
			double end = 0.0;
			while(i < n) {
				if (c[i].first + eps > (double)Z) {
					break;
				}
				if (c[i].first < end + eps) {
					end = max(end, c[i].second);
				} else {
					tot += end - begin;
					begin = c[i].first;
					end = c[i].second;
				}
				if (end + eps > (double)Z) {
					end = (double)Z;
				}
				i++;
			}
			tot += end - begin;
			return 1.0 - tot / (double)Z;
		}
};
