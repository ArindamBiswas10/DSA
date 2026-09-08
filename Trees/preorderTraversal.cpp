#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

//basically for preOrder traversal and all the other traversals are kinda the same
class Solution{
    private:
    void preorder(TreeNode* root,vector<int>& arr){
        if(!root) return;

        arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
    public:
    vector<int>preOrderTraversal(TreeNode* root){
        vector<int>arr;

        preorder(root,arr);
        return arr;
    }
};