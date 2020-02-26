/*
 * @Description: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-09-07 18:41:58
 * @LastEditTime: 2019-09-07 19:19:51
 */
#include <iostream>
#include <vector>
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
 * BFS：广度优先搜索
 * 自定向下
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
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
            int width = q.size();
            for (int i = 0; i < width; i++)
            {
                TreeNode *t = q.front();
                a.push_back(t->val);
                q.pop();
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            result.push_back(a);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
