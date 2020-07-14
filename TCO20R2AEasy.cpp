#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
class GridSpiral {
	public:
		ll findCell(int d) {
			if (d%2==0) return -1;
			if (d <= 7) return 0;
			if (d == 9) return 1;
			int d2 = (d-9)/2;
			if (d2%2==0) {
				ll x = d2/2;
				return (x+1)*(x+1);
			} else {
				ll x = d2/2;
				x++;
				return x*(x+1);
			}
		}
};
