/*
 * @Description: https://leetcode-cn.com/problems/symmetric-tree/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 19:33:56
 * @LastEditTime: 2019-09-07 19:57:21
 */
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
class Solution
{
public:
#if 0
    // 递归实现
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }

        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
#else
    // 迭代实现
    // BFS
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(root);

        while (0 == q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();

            if (t1 == nullptr && t2 == nullptr)
            {
                continue;
            }
            if (t1 == nullptr || t2 == nullptr)
            {
                return false;
            }

            if (t1->val != t2->val)
            {
                return false;
            }

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
#endif
};

int main(int argc, char const *argv[])
{

    return 0;
}
