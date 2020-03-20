// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans(k, 0);
        for (size_t i = 0; i < k; i++)
        {
            ans[i] = arr[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {0, 1, 2, 1};
    auto ans = s.getLeastNumbers(arr, 2);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
