/*
 * @Description: https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 19:20:03
 * @LastEditTime: 2019-09-07 19:32:01
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 103：二叉树层次遍历II
 * BFS：广度优先搜索
 * 自顶向下，再逆序
 */
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (0 == q.empty())
        {
            vector<int> a;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *p = q.front();
                a.push_back(p->val);
                q.pop();
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            result.push_back(a);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
