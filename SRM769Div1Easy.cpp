#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class PrimePruning {
	public:
		string maximize(int n, int e) {
			e = n-e;
			string alpha="";
			int zn = 0;
			for (int i = 2; ; ++i) {
				bool prime=true;
				for (int j = 2; j*j <= i; ++j) {
					if (i%j==0) {
						prime=false;
						break;
					}
				}
				if (prime) {
					alpha.push_back('a' + i%26);
					if (i%26 == 25) zn++;
				}
				// 可以认为素数mod26均匀分布？
				if (alpha.size() == n || zn == e) {
					break;
				}
			}
		//	cout<<"alpha="<<alpha<<endl;
			string ans="";
			for (int i = 0; i < alpha.size(); ++i) {
				while(!ans.empty()) {
					if (alpha.size()-i + ans.size()-1 >= e && alpha[i] > ans.back()) {
						ans.pop_back();
					} else {
						break;
					}
				}
				ans.push_back(alpha[i]);
			}
			return ans.substr(0, e);
		}
};
