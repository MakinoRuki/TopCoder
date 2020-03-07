#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000005
using namespace std;
typedef long long ll;
ll h[N];
ll res[2][N];
class Prominence {
	public:
		ll sumOfProminences(int n, vector<int> cf, vector<int> idx, vector<int> val) {
			for (int i = 0; i < n; ++i) {
		//		cout<<i<<endl;
				int pr = i % 2;
				ll a = cf[3*pr];
				ll b = cf[3*pr+1];
				ll c = cf[3*pr+2];
		//		cout<<pr<<" "<<a<<" "<<b<<" "<<c<<endl;
				h[i] = (((a*i+b) % 1000000007)*i + c) % 1000000007;
		//		cout<<h[i]<<endl;
			}
		//	cout<<"0"<<endl;
			for (int j = 0; j < idx.size(); ++j) {
				h[idx[j]] = val[j];
			}
		//	cout<<"1"<<endl;
			memset(res, -1, sizeof(res));
			ll maxv = 0;
			for (int i = 0; i < n; ++i) {
				maxv = max(maxv, h[i]);
			}
			// for (int i = 0; i < n; ++i) {
			// 	cout<<i<<" "<<h[i]<<endl;
			// }
			vector<int> stk;
			stk.clear();
			for (int i = 0; i < n; ++i) {
				ll minv = 1000000010;
				//res[0][i] = h[i];
				while(!stk.empty() && h[stk.back()] <= h[i]) {
					minv= min(minv, (res[0][stk.back()] < 0 ? h[stk.back()] : res[0][stk.back()]));
					stk.pop_back();
				}
				if (!stk.empty()) {
					minv = min(minv, h[i]);
					res[0][i] = minv; 
				}
				stk.push_back(i);
			}
			stk.clear();
			for (int i =n-1; i >= 0; --i) {
				ll minv = 1000000010;
				while(!stk.empty() && h[stk.back()] <= h[i]) {
					minv = min(minv, (res[1][stk.back()] < 0 ? h[stk.back()] : res[1][stk.back()]));
					stk.pop_back();
				}
				if (!stk.empty()) {
					minv = min(minv, h[i]);
					res[1][i] = minv;
				}
				stk.push_back(i);
			}
			// for (int i = 0; i < n; ++i) {
			// 	cout<<i<<" "<<res[0][i]<<" "<<res[1][i]<<endl;
			// }
			ll tot=0;
			for (int i = 0; i < n; ++i) {
				if (i == 0 && h[i] > h[i+1]) {
					if (h[i] == maxv) tot += h[i];
					else tot += h[i]-res[1][i];
				} else if (i == n-1 && h[i]>h[i-1]) {
					if (h[i] == maxv) tot += h[i];
					else tot += h[i]-res[0][i];
				} else if (i > 0 && i < n-1 && h[i] > h[i-1] && h[i] > h[i+1]) {
					if (h[i] == maxv) tot += h[i];
					else tot += h[i]-max(res[0][i], res[1][i]);
				}
			}
		//	cout<<"5"<<endl;
			return tot;
		}
};
