/*
 * @Description: https://leetcode-cn.com/problems/maximum-binary-tree/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-17 12:32:47
 * @LastEditTime: 2019-09-17 16:06:42
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        // 递归
        if (nums.empty())
        {
            return nullptr;
        }

        TreeNode *node = new TreeNode(0);

        int maxId = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[maxId] < nums[i])
            {
                maxId = i;
            }
        }

        node->val = nums[maxId];
        vector<int> left_nums = vector<int>(nums.begin(), nums.begin() + maxId);
        node->left = constructMaximumBinaryTree(left_nums);
        vector<int> right_nums = vector<int>(nums.begin() + maxId + 1, nums.end());
        node->right = constructMaximumBinaryTree(right_nums);

        return node;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution s;
    TreeNode *tree = s.constructMaximumBinaryTree(nums);
    return 0;
}
