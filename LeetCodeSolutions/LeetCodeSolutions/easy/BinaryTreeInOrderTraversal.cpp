/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<stack>
using namespace std;

class Solution {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>mystack;
        vector<int>arr;
        TreeNode* curr = root;
        TreeNode* temp = nullptr;
        while (curr || !mystack.empty())
        {
            while (curr)
            {
                mystack.push(curr);
                curr = curr->left;
            }
            temp = mystack.top();
            arr.push_back(temp->val);
            mystack.pop();
            if (temp->right)
                curr = temp->right;
        }
        return arr;
    }
};