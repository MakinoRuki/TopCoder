class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pw = 0;
        int add = 0, sub = 0;
        while(target) {
            int r = target % x;
            target /= x;
            if (pw == 0) {
                add = 2 * r;
                sub = 2 * (x - r);
            } else {
                int n_add, n_sub;
                n_add = min(pw * r + add, pw * (r + 1) + sub);
                n_sub = min(pw * (x - r) + add, pw * (x - r - 1) + sub);
                add = n_add;
                sub = n_sub;
            }
            pw++;
        }
        return min(add, pw + sub) - 1;
    }
};
