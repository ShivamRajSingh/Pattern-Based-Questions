#include "codeblock.h"

vector<int> rightSideView(TreeNode* root) {
    if(root == NULL){
        return {};
    }
    vector <int> res;
    queue <TreeNode*> q;
    q.push(root);
    while(q.empty() == false){
        int size = q.size();
        TreeNode *temp;
        for(int i =0; i < size; i++){
            temp = q.front();
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        res.push_back(temp->val);
    }
    return res;
}
int main(){
    TreeNode *root = getSampleTree();
    vector<int> res = rightSideView(root);
    print(res);
    return 0;
}
