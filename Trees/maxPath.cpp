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

int maxPathSum = INT_MIN;
int solve(TreeNode* root){
    if(!root) return 0;

    int lh = max(0,solve(root->left));

    int rh = max(0,solve(root->right));

    int maxPathSum = max(maxPathSum,lh + rh + root->data);

    return root->data + max(lh,rh);
}

int maxPath(TreeNode* root){
    solve(root);
    return maxPathSum;
}
