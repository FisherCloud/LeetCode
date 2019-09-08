/*
 * @Description: https://leetcode-cn.com/problems/invert-binary-tree/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 20:08:19
 * @LastEditTime: 2019-09-07 20:27:31
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

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 时间复杂度O(n)
        // 空间复杂度O(n)

        if (nullptr == root)
        {
            return nullptr;
        }
#if 0
        // 递归实现

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;
#else
        // 迭代方法，类似于BFS

        queue<TreeNode *> q;
        q.push(root);
        while (0 == q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            TreeNode *temp = t->left;
            TreeNode *right = t->right;
            t->left = right;
            t->right = temp;

            if (t->left)
            {
                q.push(t->left);
            }

            if (t->right)
            {
                q.push(t->right);
            }
        }
#endif
        return root;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
