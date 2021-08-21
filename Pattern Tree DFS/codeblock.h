#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

struct TreeNode{
    int val = 0;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* getSampleTree(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(7);

    return root;
}

void print(vector <int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n";
}
void print(vector<vector<int>> v){
    for(auto i : v){
        for(auto j : i)
            cout << j << " ";
        cout<<"\n";
    }
    cout << "\n";
}
