/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
//思路是遍历树节点，非叶节点就将左右子节点交换
        if(pRoot == NULL){
            return;
        }
        if(pRoot->left == NULL && pRoot->right == NULL){
            return;
        }
        TreeNode * tempNode;
        tempNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tempNode;
        //这里可以先判断是否有子树再查询
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
    void Mirror2(TreeNode *root) {
//思路2是遍历树节点，非叶节点就将左右子节点交换。
//使用循环的方法进行遍历，需要用栈来保存数据，每次都将左子节点保存到栈中。取当前节点的左子节点作为当前节点。
//在没有左子节点之后，出栈一个节点，取其右子节点作为当前节点，按照前序遍历的方式遍历。
 if(root == NULL)
        {
            return ;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        while(node != NULL
           || nstack.empty( ) != true)
        {
            while(node != NULL)
            {
                if(node->left != NULL || node->right != NULL)
                {
                    swap(node->left, node->right);
                }

                nstack.push(node);
                node = node->left;
            }

            if(nstack.empty( ) != true)
            {
                node = nstack.top( );
                nstack.pop( );
                node = node->right;
            }
        }
    }
};