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
#include <queue>
using namespace std;
bool prime[100000000];
bool rpt[100000000];
class EllysDifferentPrimes {
	public:
		int getClosest(int n) {
			memset(prime, false, sizeof(prime));
			memset(rpt, false, sizeof(rpt));
			for (int i = 2; i <= 10000; ++i) {
				if (!prime[i]) {
					for (int j = i*i; j < 60000000; j+=i) {
						prime[j] = true;
					}
				}
			}
			for (int i = 2; i < 60000000; ++i) {
				if (!prime[i]) {
					int cnt[10];
					memset(cnt, 0, sizeof(cnt));
					int x=i;
					while(x) {
						if (cnt[x%10] > 0) {
							rpt[i] = true;
							break;
						}
						cnt[x%10]++;
						x/=10;
					}
				}
			}
		//	cout<<"p="<<prime[97]<<endl;
			int res=-1;
			for (int i = 2; i < 100000000; ++i) {
				if (!prime[i] && !rpt[i]) {
					if (res<0) res=i;
					else if (abs(i-n)<abs(res-n)) {
						res=i;
					} else if (abs(i-n) == abs(res-n) && i<res) {
						res=i;
					}
				}
			}
			return res;
		}
};
