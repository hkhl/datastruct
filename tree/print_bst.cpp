#include <iostream>
#include <stack>
#include <queue>

//非递归遍历二叉树
//递归遍历二叉树
//二叉是的层序遍历



using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode():left(NULL), right(NULL){}
};

TreeNode *root = NULL;

void insert(int e)
{
    TreeNode *temp_node = new TreeNode();
    temp_node->val = e;
    temp_node->left= NULL;
    temp_node->right= NULL;

    if(root == NULL)
    {
        root = temp_node;
    }
    else
    {
        TreeNode *current = root;
        TreeNode *parent = NULL;
        while(1)
        {
            parent = current;
            if(current->val > e)
            {
                current = current->left;
                if(current == NULL)
                {
                    parent->left = temp_node;
                    return ;
                }
            }
            else
            {
                current = current->right;
                if(current == NULL)
                {
                    parent->right = temp_node;
                    return ;
                }
            }
        }
    }
}


void pre_order_traversal(TreeNode *root)
{
    if(root != NULL)
    {
        printf("%d\n", root->val);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void in_order_traversal(TreeNode *root)
{
    if(root != NULL)
    {
        in_order_traversal(root->left);
        printf("%d\n", root->val);
        in_order_traversal(root->right);
    }
}

void post_order_traversal(TreeNode *root)
{
    if(root != NULL)
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d\n", root->val);
    }
}


/*
 * 入栈的时候打印
 * 左子树全部入栈, 出栈, 入右子树
 */

void first_print(TreeNode *root)
{
    /*
    TreeNode *temp = root;
    stack<TreeNode *> s;
    while (!s.empty() || temp)
    {
        if (temp)
        {
            cout << temp->val << " ";
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }*/

    //另一种写法
    TreeNode *temp = root;
    stack<TreeNode *> s;
    s.push(temp);
    while (!s.empty())
    {
        cout << temp->val << " ";

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            temp = temp->left;
        else
        {
            temp = s.top();
            s.pop();
        }
    }
}


/*
 * 出栈的时候打印
 * 左子树全部入栈, 指向最左下元素, 出栈, 打印, 指向出栈元素的右子树
 * 存在右子树, 继续上述操作, 不存在, 接着出栈,打印,指向...
 */
void middle_print(TreeNode *root)
{
    TreeNode *temp = root;
    stack<TreeNode*> s;

    while (!s.empty() || temp)
    {
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }

        if (!s.empty())
        {
            temp = s.top();
            s.pop();
            cout << temp->val << " ";
            temp = temp->right;
        }
    }


    /*或者
    while (!s.empty() || p)
    {
        if (p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << setw(4) << p->data;
            p = p->rchild;
        }
    }
    */
    cout << endl;
}

/*
 * 1. 先左子树都入栈,
 * 2. 栈不为空
 * 3. 然后出栈,  判断是否可以打印(右子树为空, 右子树被访问过(被打印))
 * 3. 不可以打印则重新入栈, 指向右子树, 右子树的左子树全部入栈,重复上述步骤2
 */
void last_print(TreeNode *root)
{
    stack<TreeNode *> s;

    //pCpu:当前访问节点   palstVisit:上次访问节点
    TreeNode *pCur, *plastVisit;
    pCur = root;
    plastVisit = NULL;

    while (pCur)
    {
        s.push(pCur);
        pCur = pCur->left;
    }

    //左  右  中
    while (!s.empty())
    {
        //此时pCur为空没用, 获取最左下端的节点
        pCur = s.top();
        s.pop();

        //如果没有右子树, 或者右子树被访问过了  打印该节点
        if (pCur->right == NULL || pCur->right == plastVisit)
        {
            cout << pCur->val << " ";
            //修改最近访问点
            plastVisit = pCur;
        }
        else
        {
            //开始访问右子树, 将根节点重新入栈
            s.push(pCur);
            pCur = pCur->right;

            while(pCur)
            {
                s.push(pCur);
                pCur = pCur->left;
            }
        }
    }
}



void layer_print(TreeNode *root)  //层序遍历
{
    queue<TreeNode *> q;
    TreeNode *temp = root;

    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}





int main()
{
    int arr[] = {8,4,9,6,2,5,7, 10};

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        insert(arr[i]);
    }
    /*
     *in_order_traversal(root);
     *cout << endl;
     *middle_print(root);
     */

    /*
     *pre_order_traversal(root);
     *first_print(root);
     */


    /*
     *post_order_traversal(root);
     *last_print(root);
     */


    layer_print(root);

    return 0;
}
