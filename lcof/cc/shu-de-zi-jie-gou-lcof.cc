// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * isSubStructure(A, B) 函数：
     * 特例处理：
     * 当 树 A 为空 或 树 B 为空 时，直接返回 false ；
     * 返回值：
     * 若树 B 是树 A 的子结构，则必满足以下三种情况之一，因此用或 || 连接；
     * 以 节点 A 为根节点的子树 包含树 B ，对应 recur(A, B)；
     * 树 B 是树 A 左子树 的子结构，对应 isSubStructure(A.left, B)；
     * 树 B 是 树 A 右子树 的子结构，对应 isSubStructure(A.right, B)；
     */
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        return (A != nullptr && B != nullptr) &&
               (recur(A, B) || isSubStructure(A->left, B) ||
                isSubStructure(A->right, B));
    }
    /**
     * recur(A, B) 函数：
     * 终止条件：
     * 当节点 B 为空：说明树 B 已匹配完成（越过叶子节点），因此返回 true ；
     * 当节点 A 为空：说明已经越过树 A 叶子节点，即匹配失败，返回 false；
     * 当节点 A 和 B 的值不同：说明匹配失败，返回 false ；
     * 返回值：
     * 判断 A 和 B 的左子节点是否相等，即 recur(A.left, B.left) ；
     * 判断 A 和 B 的右子节点是否相等，即 recur(A.right, B.right) ；
     */
    bool recur(TreeNode *A, TreeNode *B) {
        return B == nullptr
                   ? true
                   : A == nullptr || A->val != B->val
                         ? false
                         : recur(A->left, B->left) && recur(A->right, B->right);
    }
};

int main(int argc, char const *argv[]) { return 0; }
