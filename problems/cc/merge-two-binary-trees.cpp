/*
 * @Description: https://leetcode-cn.com/problems/merge-two-binary-trees/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 20:42:56
 * @LastEditTime: 2019-09-07 21:11:19
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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        else if (t1 == nullptr)
        {
            return t2;
        }
        else if (t2 == nullptr)
        {
            return t1;
        }
        else
        {
#if 0
            // 递归
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
#else
            // 迭代
            queue<TreeNode *> q1;
            queue<TreeNode *> q2;

            TreeNode *p1 = t1;
            TreeNode *p2 = t2;

            q1.push(p1);
            q2.push(p2);

            while (q1.empty() == 0 || q2.empty() == 0)
            {
                p1 = q1.front();
                q1.pop();
                p2 = q2.front();
                q2.pop();

                if (p1 == nullptr || p2 == nullptr)
                {
                    continue;
                }

                p1->val += p2->val;

                if (p1->left == nullptr)
                {
                    p1->left = p2->left;
                }
                else
                {
                    q1.push(p1->left);
                    q2.push(p2->left);
                }

                if (p1->right == nullptr)
                {
                    p1->right = p2->right;
                }
                else
                {
                    q1.push(p1->right);
                    q2.push(p2->right);
                }
            }
#endif
            return t1;
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
