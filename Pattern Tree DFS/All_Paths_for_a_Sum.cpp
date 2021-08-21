#include "codeblock.h"

void helper (TreeNode *root , int sum , vector<int> &curr ,vector<vector<int>> &res){
    if(root == NULL)
        return;
    
    curr.push_back(root->val);

    if(root->val == sum && root->left == NULL && root->right == NULL){
        res.push_back(curr);
    }else{
        helper(root->left , sum - root->val, curr , res);
        helper(root->right , sum - root->val, curr , res);
    }

    curr.pop_back(); // To backtrack and find all possible solutions
}


vector<vector<int>> findPath( TreeNode *root , int sum){
    vector <vector<int>> res;
    vector<int> curr;
    helper(root, sum, curr, res);
    return res;
}

int main(){
    TreeNode *root = getSampleTree();
    int sum;
    cout << "Enter Sum : ";
    cin >> sum;
    vector<vector<int>> res = findPath(root, sum);
    print(res);

    return 0;
}