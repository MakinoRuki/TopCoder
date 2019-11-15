#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
const long mod = 1000000007LL;
class DeleteArrays {
public:
	long A[N], B[N], C[N];
	vector<long> doDelete(int a, int b, int c, long x, long y, long z) {
		A[0] = 33;
		A[1] = 42;
		for (int i = 2; i < a; ++i) {
			A[i] = (5*A[i-1]+7*A[i-2])%mod+1;
		}
		B[0] = 13;
		for (int i = 1; i < b; ++i) {
			B[i] = (11*B[i-1]) % mod + 1;
		}
		C[0] = 7;
		C[1] = 2;
		for (int i = 2; i < c; ++i) {
			C[i] = (5*C[i-1] + 7*C[i-2]) % mod + 1;
		}
		long sum=0;
		for (int i = 0; i < a; ++i) {
			sum += A[i];
		}
		for (int i = 0; i < b; ++i) {
			sum += B[i];
		}
		for (int i = 0; i < c; ++i) {
			sum += C[i];
		}
		sort(A, A+a);
		sort(B, B+b);
		sort(C, C+c);
		if (a >= b+c) {
			long tot=0;
			for (int i = 0; i < a-b-c; ++i) {
				tot += A[i];
			}
			return {tot, b*x+c*z+sum-tot};
		}
		if (b >= a+c) {
			long tot=0;
			for (int i = 0; i < b-a-c; ++i) {
				tot += B[i];
			}
			return {tot, a*x+c*y+sum-tot};
		}
		if (c >= a+b) {
			long tot=0;
			for (int i = 0; i < c-a-b; ++i) {
				tot += C[i];
			}
			return {tot, a*z+b*y+sum-tot};
		}
		if ((a+b+c)%2 == 0) {
			return {0, (b+c-a)/2*y+(a+b-c)/2*x+(a+c-b)/2*z+sum};
		}
		long res = -1;
		long cost = -1;
		for (int i = 0; i < 3; ++i) {
			long rem;
			if (i == 0) {
				rem = A[0];
				a--;
			} else if (i == 1) {
				rem = B[0];
				b--;
			} else if (i == 2) {
				rem = C[0];
				c--;
			}
			long tcost = (b+c-a)/2*y + (a+b-c)/2*x + (a+c-b)/2*z;
			if (res < 0 || res > rem) {
				res = rem;
				cost = tcost;
			} else if (res == rem && tcost < cost) {
				res = rem;
				cost = tcost;
			}
			if (i == 0) {
				a++;
			} else if (i == 1) {
				b++;
			} else if (i == 2) {
				c++;
			}
		}
		return {res, cost};
	}
};
