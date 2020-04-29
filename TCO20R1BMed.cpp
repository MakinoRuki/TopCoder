#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class EllysWhatDidYouGet {
	public:
		int getCount(int n) {
			int tot=0;
			for (int x=1; x<=50; ++x) {
				for (int y=1; y<=50; ++y) {
					for (int z=1; z<=50; ++z) {
						int val=-1;
						int i;
						for (i = 1; i <= n; ++i) {
							int res=(i*x+y)*z;
							int sum=0;
							while(res) {
								sum+=res%10;
								res/=10;
							}
							if (val<0) val=sum;
							else if (sum != val) break;
						}
						if (i > n) tot++;
					}
				}
			}
			return tot;
		}
};
