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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>mystack;
        vector<int>arr;
        TreeNode* curr = root;
        TreeNode* lastvisited = root;
        TreeNode* temp = nullptr;
        while (curr || !mystack.empty())
        {
            while (curr)
            {
                mystack.push(curr);
                if (curr->left)
                    lastvisited = curr;
                curr = curr->left;
            }
            temp = mystack.top();
            if (temp->right && temp->right != lastvisited)
                curr = temp->right;
            else
            {
                arr.push_back(mystack.top()->val);
                lastvisited = mystack.top();
                mystack.pop();
            }
        }
        return arr;
    }
};