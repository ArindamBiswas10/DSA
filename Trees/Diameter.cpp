#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

int diameter = 0;

int Height(TreeNode* root){
    if(!root) return 0;

    int lh = Height(root->left);

    int rh = Height(root->right);

    diameter = max(diameter,lh+rh);

    return 1 + max(lh,rh);

}

int Diameter(TreeNode* root){
    Height(root);
    return diameter;
}

