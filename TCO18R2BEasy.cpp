#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define eps 1e-9
using namespace std;
class SubarrayAverages {
	public:
		int n;
		vector<double> ans;
		vector<double> findBest(vector<int> arr) {
			n = arr.size();
			ans.clear();
			vector<double> arrd;
			for (int i = 0; i < n; ++i) {
				arrd.push_back((double)arr[i]);
			}
			for (int i = 0; i < n; ++i) {
				//cout<<i<<" "<<arrd[i]<<endl;
				double sum = arrd[i];
				double res = sum;
				int idx = i;
				for (int j = i + 1; j < n; ++j) {
					sum += arrd[j];
				//	cout<<"z"<<j<<" "<<sum / (double)(j - i + 1)<<endl;
					if (sum + eps < res * (double)(j - i + 1)) {
						res = sum / (double)(j - i + 1);
						idx = j;
					}
				}
				ans.push_back(res);
				for (int j = i; j <= idx; ++j) {
					arrd[j] = res;
				}
			}
			return ans;
		}
};
