// 有b根RG绳，对于每一个RG绳，看它的G端去连R端有三种情况：
// 1）跟自己的R端。RG绳-1，环+1，概率1/(2A+b)。
// 2）跟别的RG绳的R端。RG绳-1，环+0，概率(b-1)/(2A+b)。
// 3）跟RR绳相连。RG绳-1，环+0，概率2A/(2A+b)。
// 所以processRG绳时，永远只有每次RG绳-1，以及1/(2A+b)的概率环+1。
// 当全部变为RR/GG绳之后，对于一个RR绳的R端去连G端。假设有a根：
// 连一根GG绳的G端，概率为2/2a。变为RG绳，环+1的概率为1/(2*(a-1)+1)。
// 有a根GG绳可选。因此再乘以a。最终贡献为1/(2*(a-1)+1)。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class StringRings {
	public:
		double expectedRings(int A, int B) {
			double ans = 0.0;
			for (int b = B; b > 0; --b) {
				ans += 1.0 / (double)(2 * A + b);
			}
			for (int a = A; a > 0; --a) {
				ans += 1.0 / (double)(2 * a - 1);
			}
			return ans;
		}
};
