#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CoinConstruction {
public:
    vector<int> ans;
    vector<int> construct(int k) {
        ans.clear();
        int pw = 1;
        int tot = 1;
        while (tot <= k) {
            ans.push_back(pw);
            pw *= 2;
            tot += pw;
        }
        tot -= pw;
        if (tot < k)
        ans.push_back(k - tot);
        return ans;
    }
};
