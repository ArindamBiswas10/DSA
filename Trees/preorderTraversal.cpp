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

class Solution{
    private:
    void postorder(TreeNode* root,vector<int>& ans){
        if(!root) return;

        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    public:
    vector<int>postOrderTraversal(TreeNode* root){
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};

class Solution{
    private:
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root) return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    public:
    vector<int>inOrderTraversal(TreeNode* root){
        vector<int> ans;

        inorder(root,ans);
        return ans;
    }

};