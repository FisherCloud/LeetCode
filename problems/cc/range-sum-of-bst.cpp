/*
 * @Description: https://leetcode-cn.com/problems/range-sum-of-bst/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 15:45:56
 * @LastEditTime: 2019-08-26 16:02:00
 */
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void search(TreeNode *root, int L, int R, int &sum)
{
    if (!root)
    {
        return;
    }
    if (root->val <= R && root->val >= L)
    {
        sum += root->val;
        search(root->left, L, R, sum);
        search(root->right, L, R, sum);
    }
    else if (root->val > R)
    {
        search(root->left, L, R, sum);
    }
    else if (root->val < L)
    {
        search(root->right, L, R, sum);
    }
}

int rangeSumBST(TreeNode *root, int L, int R)
{
    int sum = 0;
    search(root, L, R, sum);
    return sum;
}

int main(int argc, char const *argv[])
{

    return 0;
}
