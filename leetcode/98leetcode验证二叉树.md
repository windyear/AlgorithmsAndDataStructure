### 98leetcode验证二叉树

#### 题目

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

#### 分析

此题利用二叉搜索树的特性进行中序遍历即可。遍历过程可以判断，提前返回。

#### 代码

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
// 中序遍历过程判断是否是升序。
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        vector<int> result;
        return inOrder(root,result);
    }
    
    // 中序遍历的过程进行比较
    bool inOrder(TreeNode* root, vector<int>& result){
        if(root == NULL){
            return true;
        }
        if(!inOrder(root->left, result)){
            return false;
        }
        if(result.empty()){
            result.push_back(root->val);
        }
        else{
            if(root->val <= result.back()){
                return false;
            }
            else{
                result.push_back(root->val);
            }
        }
        return inOrder(root->right, result);
    }
};
```

#### 总结

二叉搜索树注意利用其特点，中序遍历有序。