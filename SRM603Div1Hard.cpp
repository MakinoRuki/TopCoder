#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
typedef long long ll;
typedef struct {
	double real, imag;
}com;
com Ac[3 * N], Bc[3 * N];
class SumOfArrays {
	public:
		ll A[N], B[N];
		int cntA[N], cntB[N];
		ll ans[2 * N];
		com com_add(com a,com b) {
          return (com){a.real+b.real,a.imag+b.imag};
        }
        com com_sub(com a,com b) {
          return (com){a.real-b.real,a.imag-b.imag};
        }
        com com_mul(com a,com b) {
          return (com) {
            a.real*b.real-a.imag*b.imag,
            a.real*b.imag+a.imag*b.real
          };
        }
		void fft(com *a, int n, int flag) {
          for (int i=n/2,j=1;j<n;++j) {
              if (i<j) swap(a[i],a[j]);
              int k=n/2;
              while (i&k) {i^=k;k/=2;}
              i^=k;
          }
          for (int k=2;k<=n;k*=2) {
              com root=(com){cos(M_PI/k*flag*2),sin(M_PI/k*flag*2)};
              for (int i=0;i<n;i+=k) {
                  com w=(com){1.0, 0.0};
                  for (int j=i;j<i+k/2;++j) {
                      com u=a[j],v=com_mul(a[j+k/2],w);
                      a[j]=com_add(u,v);
                      a[j+k/2]=com_sub(u,v);
                      w=com_mul(w,root);
                  }
              }
          }
      	}
		void multiply(vector<int>& x, vector<int>& y, vector<ll>& z) {
          memset(Ac,0,sizeof(Ac));
          memset(Bc,0,sizeof(Bc));
          for (int i=0;i<100000;i++) Ac[i].real=1.0*x[i],Ac[i].imag=0.0;
          for (int i=0;i<100000;i++) Bc[i].real=1.0*y[i],Bc[i].imag=0.0;
          int len=2;
          while (len<200000) len<<=1;
          fft(Ac,len,1),fft(Bc,len,1);
          for (int i=0;i<len;i++) Ac[i]=com_mul(Ac[i],Bc[i]);
          fft(Ac,len,-1);
          for (int i=0;i<2*100000-1;i++)
              z[i]=(long long)trunc(Ac[i].real/len+0.5);
        }
		string findbestpair(int n, vector <int> Aseed, vector <int> Bseed) {
			int m = max(Aseed[5], Bseed[5]);
			A[0] = Aseed[0];
			A[1] = Aseed[1];
			B[0] = Bseed[0];
			B[1] = Bseed[1];
			for (int i = 2; i < n; ++i) {
				A[i] = (A[i - 1] * (ll)Aseed[2] + A[i - 2] * (ll)Aseed[3] + (ll)Aseed[4]) % (ll)Aseed[5];
				B[i] = (B[i - 1] * (ll)Bseed[2] + B[i - 2] * (ll)Bseed[3] + (ll)Bseed[4]) % (ll)Bseed[5];
			}
			memset(cntA, 0, sizeof(cntA));
			memset(cntB, 0, sizeof(cntB));
			for (int i = 0; i < n; ++i) {
				cntA[A[i]]++;
				cntB[B[i]]++;
			}
			memset(ans, 0, sizeof(ans));
			vector<int> numA, numB;
			for (int i = 0; i < m; ++i) {
				if (cntA[i] >= 10) numA.push_back(i);
				if (cntB[i] >= 10) numB.push_back(i);
			}
			for (auto a : numA) {
				for (auto b : numB) {
					int tm = min(cntA[a], cntB[b]);
					ans[a + b] += tm - 9;
				}
			}
			//cout<<"ok 1"<<endl;
			for (int i = 1; i < 10; ++i) {
				vector<int> x(N, 0);
				vector<int> y(N, 0);
				for (int j = 0; j < m; ++j) {
					if (cntA[j] >= i) x[j] = 1;
					if (cntB[j] >= i) y[j] = 1;
				}
				vector<ll> z(2 * N, 0);
			//	cout<<"i="<<i<<endl;
				multiply(x, y, z);
			//	cout<<"i2="<<i<<endl;
				for (int j = 0; j < z.size(); ++j) {
					ans[j] += z[j];
				}
			}
		//	cout<<"ok 2"<<endl;
		    ll X = 0, Y = -1;
			for (int i = 0; i < 2 * m; ++i) {
				if (ans[i] >= X) {
					X = ans[i];
					Y = i;
				}
			}
			return to_string(X) + " " + to_string(Y);
		}
};
