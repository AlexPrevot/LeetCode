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
class Solution {
public:
    void flatten(TreeNode* root, queue<TreeNode*>& st) {
        if (!root) return;

        st.push(root);
        flatten(root->left, st);
        flatten(root->right, st);
    }


    void flatten(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> st;
        flatten(root, st);
        st.pop();
        TreeNode* cpy = root;
        while (!st.empty()) {
            cpy->right = st.front();
            cpy->left = nullptr;
            cpy = cpy->right;
            st.pop();
        }

    }
};