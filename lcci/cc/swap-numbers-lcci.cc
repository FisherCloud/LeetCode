// https://leetcode-cn.com/problems/swap-numbers-lcci/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> swapNumbers(vector<int> &numbers)
    {
        if (numbers[0] != numbers[1])
        {
            numbers[0] ^= numbers[1];
            numbers[1] ^= numbers[0];
            numbers[0] ^= numbers[1];
        }

        return numbers;
    }
};
