#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class EllysBlood {
  public:
    int getMax(vector <int> have, vector <int> need) {
      int tot=0;
      int det=min(need[3], have[3]);
      tot += det;
      need[3] -= det;
      have[3] -= det;
      det=min(need[1], have[1]);
      tot += det;
      need[1] -= det;
      have[1] -= det;
      det =min(have[1], need[3]);
      tot += det;
      need[3] -= det;
      have[1] -= det;
      det = min(have[2], need[2]);
      tot += det;
      need[2] -= det;
      have[2] -= det;
      det = min(have[2], need[3]);
      tot += det;
      need[3] -= det;
      have[2] -= det;
      int rem=need[3]+need[2]+need[1]+need[0];
      det=min(rem, have[0]);
      tot += det;
      return tot;
    }
};
