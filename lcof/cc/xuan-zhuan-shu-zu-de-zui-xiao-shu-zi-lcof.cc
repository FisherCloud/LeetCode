// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        size_t left = 0, mid = 0, right = numbers.size() - 1;
        while (left < right)
        {
            mid = (left + right) >> 1;
            if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[left] == numbers[right])
                right--;
            else
                right = mid;
        }
        return numbers[left];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << s.minArray(nums) << endl;
    return 0;
}
