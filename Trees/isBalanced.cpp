#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

int Height(TreeNode* root){
    if(root == NULL) return 0;

    int lh = Height(root->left);
    if(lh == -1) return -1;

    int rh = Height(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh,rh);
}

bool isBalanced(TreeNode* root){
    return Height(root) != -1;
}



