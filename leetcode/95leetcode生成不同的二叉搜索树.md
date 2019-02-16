## 95leetcode生成不同的二叉搜索树

#### 题目

给定一个整数 *n*，生成所有由 1 ... *n* 为节点所组成的**二叉搜索树**。

#### 分析

以1到n分别作为头结点递归生成二叉树，左右子树分别互相组合成不同的二叉树。

#### 解答

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 套用一个快速排序的方法，递归创建
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n < 1){
            return result;
        }
        return recurGener(1, n);
    }
    
    // 一个递归产生二叉搜索树的结构。
    vector<TreeNode*> recurGener(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(NULL);
            return result;
        }
        // 以start到end分别作为头结点。
        for(int i = start; i <= end; ++i){
            vector<TreeNode*> left = recurGener(start, i-1);
            vector<TreeNode*> right = recurGener(i+1, end);
            // 合并子树。
            for(int j = 0; j < left.size(); ++j){
                for(int k = 0; k < right.size(); ++k){
                    TreeNode* head = new TreeNode(i);
                    head->left = left[j];
                    head->right = right[k];
                    result.push_back(head);
                }
            }
        }
        return result;
    }
};
```

#### 总结

生成树的算法用递归生成，此题的难点在于每个节点都可以作为根节点，且需要保存所有的树结构。