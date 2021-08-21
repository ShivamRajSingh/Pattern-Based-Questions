#include "codeblock.h"

int levelOrderSuccessor (TreeNode *root ,int n){
    if(root == NULL)
        return 0;
    
    queue <TreeNode*> q;
    q.push(root);
    while(q.empty() == false){
        TreeNode *curr = q.front();
        q.pop();
        
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }

        if(curr->val == n){
            break;
        }
    }

    return q.front()->val;

}

int main()
{
    TreeNode *root = getSampleTree();
    cout << "Level Order Successor : " << levelOrderSuccessor(root, 1);

}