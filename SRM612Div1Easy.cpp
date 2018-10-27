#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 1002
using namespace std;
class EmoticonsDiv1{
	public:
		int f[N];
		int smiles;
		int printSmiles(int smiles){
		//	smiles=_smiles;
			f[1]=0;
			for(int i=2;i<=smiles;++i){
				f[i]=i;
				for(int j=2;j<i;++j){
					int delta=i/j+(i%j!=0);
					f[i]=min(f[i],f[j]+delta+j*delta-i);
				}
			}
			return f[smiles];
		}
};
