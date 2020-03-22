// https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        int cnt[80000] = {0};
        for (int x : A)
            cnt[x]++;

        int ans = 0, taken = 0;

        for (int x = 0; x < 80000; ++x)
        {
            if (cnt[x] >= 2)
            {
                taken += cnt[x] - 1;
                ans -= x * (cnt[x] - 1);
            }
            else if (taken > 0 && cnt[x] == 0)
            {
                taken--;
                ans += x;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
