/*
 * @Author: FisherCloud 
 * @Date: 2020-02-27 09:37:16 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-27 15:52:03
 */
// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int len = inorder.size();
        if (preorder.empty() || inorder.empty()) // 序列为空
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]); // 创建根节点
        int index = 0;                              // 中序序列中根节点的位置
        while (preorder[0] != inorder[index])
            index++;                                             // 在中序序列中查找根结点位置
        preorder.erase(preorder.begin());                        // 移除先序序列中第一个元素
        vector<int>::iterator inorderiterator = inorder.begin(); // 中序遍历迭代器
        vector<int> inorderleft, inorderright;
        if (index != 0)                                                             // index != 0 说明存在左子树
            inorderleft = vector<int>(inorderiterator, inorderiterator + index);    // 左子树中序遍历
        if (index != len - 1)                                                       // 存在右子树
            inorderright = vector<int>(inorderiterator + index + 1, inorder.end()); //　右子树中序遍历
        root->left = buildTree(preorder, inorderleft);                              // 构建左子树
        root->right = buildTree(preorder, inorderright);                            // 构建右子树
        return root;                                                                // 返回构建好的树
    }
};

int main(int argc, char const *argv[])
{
    cout << "lcof-07" << endl;
    return 0;
}
