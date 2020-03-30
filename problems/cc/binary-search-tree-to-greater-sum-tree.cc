/*
 * @Description: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-30 18:14:53
 * @LastEditTime: 2019-08-30 18:27:28
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

/**
 * 中序遍历
 * 最大值保留，遍历依次加上节点的值并把值赋予当前节点
 */
int val = 0;
TreeNode *bstToGst(TreeNode *root)
{
    if (root)
    {
        bstToGst(root->right);
        val += root->val;
        root->val = val;
        bstToGst(root->left);
    }

    return root;
}

int main(int argc, char const *argv[])
{

    return 0;
}
