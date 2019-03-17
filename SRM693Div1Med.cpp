#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class BipartiteConstruction {
public:
	vector<int> ans;
	vector<int> construct (int K) {
		ans.push_back(20);
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 3; ++j) {
				ans.push_back(i * 20 + i);
			}
		}
		for (int i = 19; i >= 1; --i) {
			ans.push_back(i * 20 + i - 1);
		}
		ll det = 1LL;
		for (int i = 1; i <= 19; ++i) {
			det *= 3;
		}
		int cnt = 19;
		while(K > 0) {
		  if (det <= K){
			ans.push_back(cnt * 20 + 19);
		//	cout<<cnt<<endl;
			K -= det;
		  } else {
		  	det /= 3LL;
		  	cnt--;
		  }
		}
		return ans;
	}
};
