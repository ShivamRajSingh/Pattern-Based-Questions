#include "codeblock.h"

vector<vector<int>> levelOrder (TreeNode *root){
    queue <TreeNode*> q;
    vector<vector<int>> res;
    q.push(root);
    while(q.empty() == false){
        int level = q.size();
        vector<int> temp;
        for(int i =0; i < level; i++){
            TreeNode *curr = q.front();
            q.pop();
            temp.pb(curr->val);
            
            if(curr->left != NULL)
                q.push(curr->left);

            if(curr->right != NULL)
                q.push(curr->right);
        }
        res.pb(temp);
    }
    return res;
}

int main(){
    TreeNode *root = getSampleTree();
    vector<vector<int>> res = levelOrder (root);
    print(res);
    return 0;
}