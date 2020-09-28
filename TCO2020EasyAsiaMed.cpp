#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
class Parabola {
  public:
    vector<int> estimate(vector<int> y) {
      vector<int> ans;
      int n = y.size();
      ll maxv=-1;
      for (int a=1; a<=50; ++a) {
        for (int b = -50; b<=50; ++b) {
          vector<ll> res;
          res.clear();
          for (int i = 0; i < n; ++i) {
            ll x=(ll)y[i]-(ll)a*(ll)i*(ll)i-(ll)b*(ll)i;
            res.push_back(x);  
          }
          sort(res.begin(), res.end());
          ll det=0;
          ll c=res[0];
          for (int i = 1; i < n; ++i) {
            det += abs(res[i]-c);
          }
          ll tmpv=det;
        //  if (a==1 && b==0) {
          //  cout<<"c="<<c<<" "<<tmpv<<endl;
          //}
          for (int i = 1; i < n; ++i) {
            ll cur=res[i]-res[i-1];
            det -= (ll)(n-i)*cur;
            det += (ll)i*cur;
            if (det < tmpv) {
              tmpv=det;
              c=res[i];
            }
          //  if (a==1 && b==0) {
            //  cout<<"i="<<i<<" "<<det<<" "<<tmpv<<endl;
          //  }
          }
        //  if (a==15 && b==-49 && c==-28) {
          //  cout<<"xxx="<<tmpv<<endl;
        //  }
        //  if (a==1 && b==0 && c==0) {
          //  cout<<"xx="<<tmpv<<" "<<maxv<<endl;
          //}
          if (maxv<0) {
            maxv=tmpv;
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(c);
          } else if (tmpv<maxv || (tmpv==maxv && a<ans[0]) || (tmpv==maxv && a==ans[0] && b < ans[1]) || (tmpv==maxv && a==ans[0] && b==ans[1] && c<ans[2])) {
            maxv=tmpv;
            ans.clear();
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(c);
          }
        }
      }
      return ans;
    }
};
