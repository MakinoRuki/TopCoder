#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class NearPalindromesDiv1 {
	public:
		int solve(string s) {
			int cnt[26];
			memset(cnt, 0, sizeof(cnt));
			int n = s.size();
			for (int i = 0; i < n; ++i) {
				cnt[s[i]-'a']++;
			}
		//	for (int i = 0; i < 26; ++i) {
			//	cout<<i<<" "<<cnt[i]<<endl;
		//	}
			int ans=26*(n+1);
			for (int i = 0; i < 26; ++i) {
				if (cnt[i]%2) {
					for (int st=0;st<26; ++st) {
						int pre=-1;
						int tot=0;
						for (int j = 0; j < 26; ++j) {
							int j2=(st+j)%26;
							if (j2==i) continue;
							if (cnt[j2]%2==0) continue;
							if (pre>=0) {
								tot += min((pre-j2+26)%26, (j2-pre+26)%26);
								pre=-1;
							} else {
								pre=j2;
							}
						}
						if (pre<0) ans=min(ans, tot);
					}
				}
			}
			for (int st=0;st<26; ++st) {
				int pre=-1;
				int tot=0;
				for (int i = 0; i < 26; ++i) {
					int i2=(i+st)%26;
					if (cnt[i2]%2) {
						if (pre>=0) {
							tot += min((pre-i2+26)%26, (i2-pre+26)%26);
							pre=-1;
						} else {
							pre=i2;
						}
					}
				}
				if (pre<0) ans=min(ans, tot);
			}
			return ans;
		}
};
