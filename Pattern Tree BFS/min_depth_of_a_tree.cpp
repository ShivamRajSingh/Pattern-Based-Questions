#include "codeblock.h"

int minDepth (TreeNode *root){
    if(root == NULL)
        return 0;
    
    queue<TreeNode*> q;
    int minimumDepth = 0;
    q.push(root);
    while(q.empty() == false){
        minimumDepth++;
        
        int levelSize = q.size();
        for(int i =0; i < levelSize; i++){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left == NULL && curr->right == NULL){
                return minimumDepth;
            }

            if(curr->left != NULL){
                q.push(curr->left);
            }
            
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    return minimumDepth;
}
int main()
{
    TreeNode *root = getSampleTree();
    cout << "Minimum Depth : " << minDepth(root);
}